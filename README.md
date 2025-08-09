# TRIE-AUTOCOMPLETE

A fast and efficient autocomplete web application using a Trie data structure implemented in C++ for the backend, and React for the frontend.

## Features

- Insert new words dynamically into the trie and save them persistently.
- Autocomplete suggestions based on user input prefix.
- Simple REST API backend built with C++ and httplib.
- React frontend with smooth user experience and loading states.
- Dockerized for easy deployment.

## Tech Stack

- Backend: C++ (Trie data structure, httplib, nlohmann/json)
- Frontend: React, Axios, Vite
- Deployment: Docker, Docker Compose

## How to Run

### Locally

1. Clone the repo
2. Build and run backend and frontend using Docker Compose:

```bash
docker-compose up --build
