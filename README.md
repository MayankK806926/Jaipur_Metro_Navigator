# Jaipur Metro Navigator 🚇

[![C++ Version](https://img.shields.io/badge/C++-17-blue.svg)](https://en.cppreference.com/w/cpp/17)

A comprehensive C++ application for navigating the Jaipur Metro system, featuring route planning, station information, and interactive metro maps.

## Features ✨

- 🗺️ Interactive metro map display
- 🔍 Find shortest routes between stations
- ℹ️ Detailed station information
- 📏 Distance calculations between stations
- 🔄 Interchange station detection
- 🎯 Simple, menu-driven interface
- 🏗️ Object-Oriented Design with proper encapsulation
- ⚡ Efficient algorithms for optimal pathfinding

## Technical Implementation 🛠️

### Object-Oriented Programming
- **Encapsulation**: Station data and operations wrapped in classes
- **Modular Design**: Separate classes for metro network, station, and pathfinding
- **Abstraction**: Complex operations hidden behind simple interfaces
- **STL Containers**: Leveraged for efficient data management

### Data Structures & Algorithms
- **Graph Theory**: Metro network modeled as weighted graph
- **Dijkstra's Algorithm**: For finding shortest paths (O(E + V log V) complexity
- **Priority Queues**: Used in pathfinding implementation
- **Hash Maps**: For O(1) station lookups
- **Adjacency Lists**: To store station connections

## Installation ⚙️

### Prerequisites
- C++17 compatible compiler (g++, clang, or MSVC)
- CMake (optional, for building)

### Building from Source
```bash
git clone https://github.com/MayankK806926/jaipur-metro-navigator.git
cd jaipur-metro-navigator
g++ -std=c++17 main.cpp -o jaipur_metro
```

### Running the program
```bash
./jaipur_metro
```

### Usage 🖥️
The program provides an interactive menu system:
- **List All Stations**: View all stations organized by metro line
- **Display Metro Map**: See the complete Jaipur Metro network
- **Plan Journey**: Find the shortest route between two stations
- **Station Information**: Get details about any station
- **Exit**: Quit the program

### Data Structure 🏗️
The application uses:
- Graph representation of the metro network
- Dijkstra's algorithm for pathfinding
- Hash maps for efficient station lookups
- Priority queues for route optimization

### Jaipur Metro Network ℹ️
The program includes complete data for:
- **Pink Line (Line 1)**: Mansarovar ↔ Sindhi Camp (9.8 km)
- **Yellow Line (Line 2)**: Badi Chaupar ↔ Shyam Nagar (3.8 km)

Made with ❤️ in RAJASTHAN

🙏🙏 Khamma Ghanni 🙏🙏
