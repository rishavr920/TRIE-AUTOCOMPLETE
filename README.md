# Trie Autocomplete

High-performance Trie-based Autocomplete engine with a C++ backend and React frontend.

## Run locally

### Backend

1. Download `httplib.h` into `backend/` from: https://github.com/yhirose/cpp-httplib
2. Add `backend/words.txt` (a list of words, one per line). You can use `words_alpha.txt`.
3. Build and run:

```bash
cd backend
mkdir build && cd build
cmake ..
make
./trie_server
```

Server listens on port 8080.

### Frontend

```bash
cd frontend
npm install
npm run dev
```

Vite proxies `/suggest` and `/insert` to the backend in development.

## Deployment

- For quick demo: build Docker image and run on any container host.
- For resume-cool: compile Trie to WebAssembly with Emscripten and bundle with React.

