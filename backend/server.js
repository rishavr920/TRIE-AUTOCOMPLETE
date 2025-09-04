const express = require("express");
const bodyParser = require("body-parser");
const cors = require("cors");
const { execFile } = require("child_process");

const app = express();
app.use(cors());
app.use(bodyParser.json());

// Insert word
app.post("/insert", (req, res) => {
  const { word } = req.body;
  if (!word) return res.status(400).json({ error: "word required" });

  execFile("./build/trie", ["insert", word], (err, stdout, stderr) => {
    if (err) return res.status(500).json({ error: stderr });
    res.json({ status: stdout.trim() });
  });
});

// Autocomplete
app.get("/autocomplete/:prefix", (req, res) => {
  const { prefix } = req.params;
  execFile("./build/trie", ["autocomplete", prefix], (err, stdout, stderr) => {
    if (err) return res.status(500).json({ error: stderr });
    try {
      res.json(JSON.parse(stdout));
    } catch {
      res.status(500).json({ error: "invalid response from trie" });
    }
  });
});

app.listen(8080, () => {
  console.log("Node server running at http://localhost:8080");
});
