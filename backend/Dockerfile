# Use official C++ image with cmake & build tools
FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential cmake git curl \
    && rm -rf /var/lib/apt/lists/*

# Install dependencies for httplib and nlohmann json
RUN apt-get update && apt-get install -y \
    nlohmann-json3-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN cmake -B build -S . && cmake --build build

EXPOSE 8080

CMD ["./build/trie_server"]
