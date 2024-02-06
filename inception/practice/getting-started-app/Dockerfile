# syntax=docker/dockerfile:1

# FROM node:18-alpine
# WORKDIR /app
# COPY . .
# RUN yarn install --production
# CMD ["node", "src/index.js"]
# EXPOSE 3000

# FROM node:18-alpine
# WORKDIR /app
# COPY package.json yarn.lock ./
# RUN yarn install --production
# COPY . .
# CMD ["node", "src/index.js"]

FROM node:18-alpine as builder
WORKDIR /app
COPY package.json yarn.lock ./
RUN yarn install
COPY . .

FROM node:18-alpine
WORKDIR /app
COPY --from=builder /app/src ./src
COPY --from=builder /app/node_modules ./node_modules
CMD ["node", "src/index.js"]


