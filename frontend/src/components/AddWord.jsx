import React, { useState } from "react";
import axios from "axios";

export default function AddWord() {
  const [word, setWord] = useState("");
  const [msg, setMsg] = useState("");
  const BASE_URL = import.meta.env.VITE_BACKEND_URL || "http://localhost:8080";

const handleAdd = () => {
  if (!word.trim()) return;
  axios
    .post(`${BASE_URL}/insert`, { word })
    .then((res) => {
      setMsg("Word added successfully!");
      setWord("");
      setTimeout(() => setMsg(""), 3000);
    })
    .catch((err) => {
      console.error("Add word error:", err);
      setMsg("Error adding word");
      setTimeout(() => setMsg(""), 3000);
    });
};

  return (
    <div style={{ marginTop: 20 }}>
      <input
        value={word}
        onChange={(e) => setWord(e.target.value)}
        placeholder="New word"
      />
      <button onClick={handleAdd}>Add Word</button>
      <div>{msg}</div>
    </div>
  );
}
