import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'

export default defineConfig({
  plugins: [react()],
  server: {
 proxy: {
      '/insert': 'http://localhost:8080',
      '/autocomplete': 'http://localhost:8080',
    }
  }
})
