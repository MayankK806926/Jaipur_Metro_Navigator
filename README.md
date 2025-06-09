# Jaipur Metro Navigator 🚇

[![GitHub license](https://img.shields.io/github/license/yourusername/jaipur-metro-navigator)](https://github.com/yourusername/jaipur-metro-navigator/blob/main/LICENSE)
[![C++ Version](https://img.shields.io/badge/C++-17-blue.svg)](https://en.cppreference.com/w/cpp/17)

A comprehensive C++ application for navigating the Jaipur Metro system, featuring route planning, station information, and interactive metro maps.

![Jaipur Metro Screenshot](screenshot.png) <!-- Add actual screenshot later -->

## Features ✨

- 🗺️ Interactive metro map display
- 🔍 Find shortest routes between stations
- ℹ️ Detailed station information
- 📏 Distance calculations between stations
- 🔄 Interchange station detection
- 🎯 Simple, menu-driven interface

## Installation ⚙️

### Prerequisites
- C++17 compatible compiler (g++, clang, or MSVC)
- CMake (optional, for building)

### Building from Source
```bash
git clone https://github.com/yourusername/jaipur-metro-navigator.git
cd jaipur-metro-navigator
g++ -std=c++17 main.cpp -o jaipur_metro
```
### Running the program
```bash
./jaipur_metro
```

### Usage 🖥️
The program provides an interactive menu system:

List All Stations: View all stations organized by metro line

Display Metro Map: See the complete Jaipur Metro network

Plan Journey: Find the shortest route between two stations

Station Information: Get details about any station

Exit: Quit the program

Data Structure 🏗️
The application uses:

Graph representation of the metro network

Dijkstra's algorithm for pathfinding

Hash maps for efficient station lookups

Priority queues for route optimization

Jaipur Metro Network ℹ️
The program includes complete data for:

Pink Line (Line 1): Mansarovar ↔ Sindhi Camp (9.8 km)

Yellow Line (Line 2): Badi Chaupar ↔ Shyam Nagar (3.8 km)

Contributing 🤝
Contributions are welcome! Please follow these steps:

Fork the repository

Create your feature branch (git checkout -b feature/AmazingFeature)

Commit your changes (git commit -m 'Add some AmazingFeature')

Push to the branch (git push origin feature/AmazingFeature)

Open a Pull Request

License 📄
This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgments 🙏
Jaipur Metro Rail Corporation for network information

Rajasthan Transport Department for public data

The C++ community for excellent resources

Made with ❤️ in Jaipur 