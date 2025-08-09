import React from 'react'
import AutoComplete from './components/AutoComplete'
import AddWord from './components/AddWord'

export default function App(){
  return (
    <div style={{padding:20, fontFamily:'Arial'}}>
      <h2>Trie Autocomplete Demo</h2>
      <AutoComplete />
      <AddWord/>
    </div>
  )
}
