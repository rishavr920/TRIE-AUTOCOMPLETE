import React, { useState, useEffect } from 'react'
import axios from 'axios'
import Loading from './Loading'

export default function AutoComplete(){
  const [q, setQ] = useState('')
  const [sugs, setSugs] = useState([])
  const [loading, setLoading] = useState(false)
  const BASE_URL = import.meta.env.VITE_BACKEND_URL || "http://localhost:8080";

  useEffect(()=>{
    if(q.length===0){ 
      setSugs([]); 
      setLoading(false);
      return
     }
    setLoading(true)
    const id = setTimeout(()=>{
      axios.get(`${BASE_URL}/autocomplete/${encodeURIComponent(q)}`)
        .then(r=>{ setSugs(r.data); setLoading(false) })
        .catch(e=>{ setSugs([]); setLoading(false) })
    }, 300)
    return ()=> clearTimeout(id)
  }, [q])

  return (
    <div style={{maxWidth:520}}>
      <input
        style={{width:'100%', padding:8, fontSize:16}}
        value={q}
        onChange={e=>setQ(e.target.value)}
        placeholder="Type to search..."
      />
      {loading && <Loading/>}
      <ul style={{listStyle:'none', padding:0}}>
        {sugs.map((s,i)=>{
          const bold = s.slice(0, q.length)
          const rest = s.slice(q.length)
          return (
            <li key={i} style={{padding:'6px 4px'}}>
              <strong>{bold}</strong>{rest}
            </li>
          )
        })}
      </ul>
    </div>
  )
}
