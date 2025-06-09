#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

class Jaipur_Metro {
private:
    // Station structure to store metro station information
    struct Station {
        string station_name;  // Name of the station
        string station_line;  // Line the station belongs to (e.g., "Pink", "Yellow")
        bool isInterchange = false;  // Whether the station is an interchange
        unordered_map<string, int> connections;  // Connected stations with distances in meters
    };
    
    // Data structures to store metro network information
    unordered_map<string, Station> stations;  // All stations by name
    unordered_map<string, vector<string>> lines;  // Stations organized by line
    unordered_map<string, string> stationCodes;  // Short codes for each station

    // Structure to store path information (not currently used in main functions)
    struct pathInfo {
        int distance;  // Total distance in meters
        int time;      // Estimated time in minutes
        vector<string> path;  // Sequence of stations
    };

public:
    /**
     * Adds a station to the metro network
     * @param name Station name
     * @param line Line name ("Pink"/"Yellow")
     * @param isInterchange Whether station connects multiple lines
     */
    void addStation(const string& name, const string& line, const bool isInterchange) {
        if(stations.find(name) == stations.end()) {
            stations[name] = {name, line, isInterchange, {}};
        } else {
            if(isInterchange) stations[name].station_line += "/" + line;  // Mark as interchange
        }
        lines[line].push_back(name);
    }

    /**
     * Adds a connection between two stations
     * @param station1 First station name
     * @param station2 Second station name
     * @param gap Distance between stations in kilometers
     */
    void addConnection(const string& station1, const string& station2, double gap) {
        int distanceInMeters = (gap * 1000);  // Convert km to meters
        stations[station1].connections[station2] = distanceInMeters;
        stations[station2].connections[station1] = distanceInMeters;
    }

    // Initializes the Jaipur Metro network with stations and connections
    void initializeNetwork() {
        // Pink Line (Line 1) stations
        addStation("Mansarovar", "Pink", false);
        addStation("New Aatish Market", "Pink", false);
        addStation("Vivek Vihar", "Pink", false);
        addStation("Shyam Nagar", "Pink", true);  // Interchange
        addStation("Ram Nagar", "Pink", false);
        addStation("Civil Lines", "Pink", false);
        addStation("Railway Station", "Pink", false);
        addStation("Sindhi Camp", "Pink", true);  // Interchange
        
        // Yellow Line (Line 2) stations
        addStation("Badi Chaupar", "Yellow", false);
        addStation("Chandpole", "Yellow", false);
        addStation("Sindhi Camp", "Yellow", true);  // Interchange
        addStation("Shyam Nagar", "Yellow", true);  // Interchange

        // Pink Line connections with distances in km
        addConnection("Mansarovar", "New Aatish Market", 1.2);
        addConnection("New Aatish Market", "Vivek Vihar", 1.1);
        addConnection("Vivek Vihar", "Shyam Nagar", 1.3);
        addConnection("Shyam Nagar", "Ram Nagar", 0.8);
        addConnection("Ram Nagar", "Civil Lines", 1.0);
        addConnection("Civil Lines", "Railway Station", 0.9);
        addConnection("Railway Station", "Sindhi Camp", 0.7);
        
        // Yellow Line connections with distances in km
        addConnection("Badi Chaupar", "Chandpole", 0.5);
        addConnection("Chandpole", "Sindhi Camp", 0.8);
        addConnection("Sindhi Camp", "Shyam Nagar", 1.5);

        generateStationCodes();  // Create short codes for all stations
    }

    // Generates 3-letter codes for each station (e.g., "MSR" for Mansarovar)
    void generateStationCodes() {
        int i = 1;
        for(auto& station : stations) {
            string code;
            string name = station.first;

            // Create code from station name initials
            size_t pos = 0;
            while ((pos = name.find(' ')) != string::npos) {
                code += toupper(name[0]);
                name.erase(0, pos + 1);
            }
            code += toupper(name[0]);
            
            // Add line identifier (first letter)
            string line = stations[station.first].station_line.substr(0, 1);
            code += line;
            
            // Handle duplicate codes
            if (stationCodes.find(code) != stationCodes.end()) {
                code += to_string(i);
            }
            
            stationCodes[station.first] = code;
            i++;
        }
    }

    // Displays the complete metro network map
    void displayFullMap() {
        cout << "\n------------ JAIPUR METRO NETWORK MAP ------------\n";
        cout << "=> Pink Line (Line 1): Mansarovar to Sindhi Camp (9.8 km)\n";
        cout << "=> Yellow Line (Line 2): Badi Chaupar to Shyam Nagar (3.8 km)\n\n";

        for(const auto& line : lines) {
            cout << "Line " << line.first << ":\n";
            cout << " ";
            for(size_t i = 0; i < line.second.size(); ++i) {
                cout << line.second[i];
                if(stations[line.second[i]].isInterchange) {
                    cout << " <->";  // Interchange symbol
                }
                if (i != line.second.size() - 1) {
                    double distance = stations[line.second[i]].connections[line.second[i+1]] / 1000.0;
                    cout << " -- (" << fixed << setprecision(1) << distance << "km) -- ";
                }
            }
            cout << "\n\n";
        }
        cout << "<-> indicates interchange stations\n";
        cout << "--------------------------------------------------\n";
    }

    // Displays all stations organized by line
    void displayAllStations() {
        cout << "\n-------- JAIPUR METRO STATIONS --------\n";
        cout << "Total Stations: " << stations.size() << "\n\n";
        
        int i=1;//To print numbering.
        cout << "Pink Line (Line 1):\n";
        for (const auto& station : lines["Pink"]) {
            cout << "  "<< i<< ". " << setw(20) << left << station 
                 << " (" << stationCodes[station] << ")";
            if (stations[station].isInterchange) {
                cout << " [Interchange]";
            }
            cout << "\n";
            i++;
        }
        
        i=1;
        cout << "\nYellow Line (Line 2):\n";
        for (const auto& station : lines["Yellow"]) {
            cout << "  "<< i<< ". " << setw(20) << left << station 
                 << " (" << stationCodes[station] << ")";
            if (stations[station].isInterchange) {
                cout << " [Interchange]";
            }
            cout << "\n";
            i++;
        }
        cout << "--------------------------------------\n";
    }

    /**
     * Finds shortest path between two stations using Dijkstra's algorithm
     * @param src Source station name
     * @param dest Destination station name
     * @return Vector of station names representing the path
     */
    vector<string> findShortestPath(const string& src, const string& dest) {
        unordered_map<string, int> dist;  // Distance from source
        unordered_map<string, string> prev;  // Previous station in path
        // Priority queue for Dijkstra's (min-heap by distance)
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        // Initialize distances
        for(const auto& station : stations) {
            dist[station.first] = INT_MAX;
        }

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            string curr = pq.top().second;
            pq.pop();

            if(curr == dest) break;  // Reached destination

            // Explore neighbors
            for(const auto& neighbor : stations[curr].connections) {
                string next = neighbor.first;
                int newDist = dist[curr] + neighbor.second;

                if(newDist < dist[next]) {  // Found shorter path
                    dist[next] = newDist;
                    prev[next] = curr;
                    pq.push({newDist, next});
                }
            }
        }

        // Reconstruct path
        vector<string> path;
        string curr = dest;
        while(curr != "") {
            path.push_back(curr);
            curr = prev[curr];
        }
        reverse(path.begin(), path.end());

        return path;
    }

    /**
     * Displays detailed route information between two stations
     * @param src Source station name
     * @param dest Destination station name
     */
    void displayRouteDetails(const string& src, const string& dest) {
        if(stations.find(src) == stations.end() || stations.find(dest) == stations.end()) {
            cout << "\nError: Please check station names!\n";
            return;
        }

        vector<string> path = findShortestPath(src, dest);
        if(path.empty()) {
            cout << "\nNo path found between stations!\n";
            return;
        }
        
        cout << "\n-------- ROUTE DETAILS --------\n";
        cout << "FROM: " << src << " (" << stationCodes[src] << ")\n";
        cout << "TO:   " << dest << " (" << stationCodes[dest] << ")\n";
        cout << "------------------------------\n";

        cout << "\n=> Route Summary:\n";
        cout << "  Total Stations: " << path.size() << "\n";
        cout << "  Total Distance: " << fixed << setprecision(1) 
             << (calDistance(path)/1000.0) << " km\n";

        cout << "\n=> Detailed Path:\n";
        string currentLine = stations[path[0]].station_line;
        cout << "  -> Board at " << path[0] << " on " << currentLine << " line\n";

        for(size_t i = 1; i < path.size(); ++i) {  // Fixed: changed ',' to ';' in loop
            if(stations[path[i]].station_line != currentLine) {
                cout << "  => Change to " << stations[path[i]].station_line 
                     << " line at " << path[i] << "\n";
                currentLine = stations[path[i]].station_line;
            }
            if (i == path.size() - 1) {
                cout << "  -> Exit at " << path[i] << "\n";
            }
        }
        cout << "------------------------------\n";
    }

    // Calculates total distance of a path in meters
    int calDistance(const vector<string>& path) {
        int dist = 0;
        for(size_t i = 0; i < path.size() - 1; ++i) {
            dist += stations[path[i]].connections[path[i+1]];
        }
        return dist;
    }

    // Displays detailed information about a specific station
    void showStationInfo(const string& station_name) {
        if(stations.find(station_name) == stations.end()) {
            cout << "Station Not Found!\nPlease check station name!\n";
            return;
        }

        cout << "\n-------- STATION INFORMATION --------\n";
        cout << "=> Name: " << station_name << "\n";
        cout << "=> Code: " << stationCodes[station_name] << "\n";
        cout << "=> Line: " << stations[station_name].station_line << "\n";
        cout << "=> Interchange: " << (stations[station_name].isInterchange ? "Yes" : "No") << "\n";
        
        cout << "\n=> Connected Stations:\n";
        for (const auto& conn : stations[station_name].connections) {
            double distance = conn.second / 1000.0;
            cout << "  -> " << setw(20) << left << conn.first 
                 << " (" << fixed << setprecision(1) << distance << " km)\n";
        }
        cout << "--------------------------------------\n";
    }

    // Displays the main menu options
    void showOptionsMenu() {
        cout << "\n-------- JAIPUR METRO NAVIGATOR --------\n";
        cout << "1. List All Stations\n";
        cout << "2. Display Metro Map\n";
        cout << "3. Plan Journey\n";
        cout << "4. Station Information\n";
        cout << "5. Exit\n";
        cout << "--------------------------------------\n";
        cout << "Enter your choice (1-5): ";
    }

    // Main application loop
    void run() {
        initializeNetwork();
        cout << "\n WELCOME TO JAIPUR METRO NAVIGATOR \n";
        cout << "=> We have " << stations.size() << " Stations \n=> Along " << lines.size() << " Lines \n";

        while(true) {
            showOptionsMenu();
            int choice;
            cin >> choice;
            cin.ignore();

            if(choice == 5) {
                cout<<"\nThank You for using Jaipur Metro Navigator \n ||| Khamma Ghanni |||\n";
                break;
            }

            switch(choice) {
                case 1:
                    displayAllStations();
                    break;
                case 2:
                    displayFullMap();
                    break;
                case 3: {
                    string src, dest;
                    cout << "\nEnter Boarding Station: ";
                    getline(cin, src);
                    cout << "Enter Destination Station: ";
                    getline(cin, dest);
                    displayRouteDetails(src, dest);
                    break;
                }
                case 4: {
                    string station;
                    cout << "\nEnter Station Name: ";
                    getline(cin, station);
                    showStationInfo(station);
                    break;
                }
                default:
                    cout << "Invalid choice. Please try again.\n";
            }

            cout<<"Do you want to continue on Jaipur Metro Navigator? (y/n) : ";
            char input;cin>>input;
            if(input=='n' || input=='N'){
                cout<<"\nThank You for using Jaipur Metro Navigator \n ||| Khamma Ghanni |||\n";
                break;
            }
        }
    }
};

int main() {
    Jaipur_Metro metro;
    metro.run();
    return 0;
}