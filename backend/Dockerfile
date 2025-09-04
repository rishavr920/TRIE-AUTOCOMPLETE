# Use Ubuntu with build tools
FROM ubuntu:22.04

# Install compiler + cmake + json lib
RUN apt-get update && apt-get install -y \
    build-essential cmake git curl nlohmann-json3-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy source files
COPY . .

# Build trie binary
RUN cmake -B build -S . && cmake --build build

# Default command (runs trie help if no args given)
CMD ["./build/trie", "--help"]
