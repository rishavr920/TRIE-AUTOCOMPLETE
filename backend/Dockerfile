FROM node:18

# Install C++ build tools & json lib
RUN apt-get update && apt-get install -y \
    build-essential cmake git curl nlohmann-json3-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy package.json first for caching
COPY package*.json ./

# Install Node dependencies
RUN npm install

# Copy all source files
COPY . .

# Build C++ trie binary
RUN cmake -B build -S . && cmake --build build

EXPOSE 8080

# Start Node server
CMD ["npm", "start"]
