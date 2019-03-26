#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iterator>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::next;
using std::prev;
using std::stringstream;
using std::istringstream;
using std::istream_iterator;
using std::ostream_iterator;

struct Coord {
  int x;
  int y;
  char orientation;
  Coord() : x(0), y(0), orientation('N') {};
  Coord(int x, int y) : x(x), y(y), orientation('N') {}
};

int main() {
  vector<struct Coord> dangerCoords;
  struct Coord robotCoord;
  struct Coord gridSize;

  string test;
  string path;
  bool stopWalking = false;
  bool lostRobot = false;

  map<char, struct Coord> angle;

  angle['N'] = Coord(0, 1);
  angle['E'] = Coord(1, 0);
  angle['S'] = Coord(0, -1);
  angle['W'] = Coord(-1, 0);

  cin >> gridSize.x;
  cin >> gridSize.y;
  cin.ignore();
  
  while(getline(cin, test)) {
    istringstream iss(test);
    lostRobot = false;
    // cin >> robotCoord.x;
    iss >> robotCoord.x;
    // cin >> robotCoord.y;
    iss >> robotCoord.y;
    // cin >> robotCoord.orientation;
    iss >> robotCoord.orientation;

    cin >> path;
    cin.ignore();

    for(char& c : path) {
      if(lostRobot) break;
      stopWalking = false;

      switch(c) {
        case 'R': {
          if(robotCoord.orientation == 'N') robotCoord.orientation = 'E';
          else if(robotCoord.orientation == 'E') robotCoord.orientation = 'S';
          else if(robotCoord.orientation == 'S') robotCoord.orientation = 'W';
          else if(robotCoord.orientation == 'W') robotCoord.orientation = 'N';

          break;
        }
        case 'L': {
          if(robotCoord.orientation == 'N') robotCoord.orientation = 'W';
          else if(robotCoord.orientation == 'E') robotCoord.orientation = 'N';
          else if(robotCoord.orientation == 'S') robotCoord.orientation = 'E';
          else if(robotCoord.orientation == 'W') robotCoord.orientation = 'S';

          break;
        }
        case 'F': {
          for(int i=0; i < dangerCoords.size(); i++) {
            if(dangerCoords[i].x == robotCoord.x && dangerCoords[i].y == robotCoord.y) {
              stopWalking = true;
            }
          }

          robotCoord.x += angle[robotCoord.orientation].x;
          robotCoord.y += angle[robotCoord.orientation].y;

          if(robotCoord.x > gridSize.x) {
            lostRobot = !stopWalking;
            robotCoord.x -= 1;
          }

          if(robotCoord.x < 0) {
            lostRobot = !stopWalking;
            robotCoord.x += 1;
          }

          if(robotCoord.y > gridSize.y) {
            lostRobot = !stopWalking;
            robotCoord.y -= 1;
          }

          if(robotCoord.y < 0) {
            lostRobot = !stopWalking;
            robotCoord.y += 1;
          }

          break;
        }
      }
    }

    if(!lostRobot) {
      cout << robotCoord.x;
      cout << " " << robotCoord.y << " " << robotCoord.orientation << endl;
    } else {
      cout << robotCoord.x;
      cout << " " << robotCoord.y << " " << robotCoord.orientation << " LOST" << endl;

      dangerCoords.push_back(Coord(robotCoord.x, robotCoord.y));
    }
  }
}