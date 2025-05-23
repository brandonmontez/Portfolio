// gar.cpp
// Brandon Montez
// 12/16/21

// https://drive.google.com/file/d/1yJmPgxGUx9QWSpakj9g7G3SWQ3rjUjTr/view

#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
// idk if i need these libraries but im not risking it
#include <cstdlib>
#include <ctime>

// colors for the map (idea yoinked from Dylan K.)
#define RESET   "\033[0m"
#define MAGENTA "\033[35m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

using namespace std;


// GLOBALS you can change. things may break and runtime may vary.
static const int  MAP_SIZE = 12,  // includes 2 walls (LOWERING THIS CAN BREAK STUFF BUT IT CAN ALSO WORK, IDK. TRY BIG MAPS. DEFAULT 12.)
                  TOT_BATS = (pow(MAP_SIZE-2,2)*0.4),  // total batteries on map = 40% of the area
                  GENS = 250,  // amount of generations tested
                  TOT_BOTS = 200,  // amount of bots per population

                  SHOW_ROB = 1,  // number of robots to display on the final generation // OPTIONAL
                  PENALTY = 1,  // penalty from score for running into wall (ex: "1" is minus one from score) // OPTIONAL
                  NUM_WALLS = 0;  // number of walls in playing field must be below (1 - perc batteries) // OPTIONAL


class Roomba {
  private:
    static const int  OPEN = 0,
                      BATT = 1,
                      WALL = 2,
                      DONUT = 3,
                      
                      NORTH = 0,
                      EAST = 1,
                      SOUTH = 2,
                      WEST = 3,
                      RAND = 4;
                    
  public:
    int gene[16][5],
        sensor[4],
        
        energy = 5,
        percentage = 0,
        batt_count = 0,
        wall_count = 0,

        map[MAP_SIZE][MAP_SIZE],

        y_pos = 0,
        x_pos = 0;


    double score = 0.0,
           batt_percentage = 0.0;  // using for testing

    Roomba() {
      // Initializes genes.
      // The first four members of each row are random ints 0-3 corresponding to sensors (nothing, battery, dont_care, wall).
      // The fifth member is an int 0-4 corresponding to the action (N, S, E, W, Random).
      for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 5; j++) {
          if (j == 4) {
            gene[i][j] = rand() % 5;
          }
          else {
            gene[i][j] = rand() % 4;
          }
        }
      }
    }

    void make_map() {
      int row = 0;
      int col = 0;

      for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
          if (i == 0 || i == (MAP_SIZE - 1)) {
            map[i][j] = WALL;
          }
          else if (j == 0 || j == (MAP_SIZE - 1)) {
            map[i][j] = WALL;
          }
          else {
            map[i][j] = OPEN;
          }
        }
      }

      while (batt_count < TOT_BATS) {
        // only inputting batteries into spaces that are at least 1 tile away from wall
        // this incentivizes bots to move away from walls rather than adjacent to them.
        row = (rand() % (MAP_SIZE - 4) + 2);
        col = (rand() % (MAP_SIZE - 4) + 2);

        if (map[row][col] == OPEN) {
          map[row][col] = BATT;
          batt_count++;
        }
      } 

      // optional to place walls in map
      while (wall_count < NUM_WALLS) {
        row = (rand() % (MAP_SIZE - 2) + 1);
        col = (rand() % (MAP_SIZE - 2) + 1);

        if (map[row][col] == OPEN) {
          map[row][col] = WALL;
          wall_count++;
        }
      }              
    }

    void show_map () {
      cout << endl;
      for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
          if (i == y_pos && j == x_pos) {
            cout << MAGENTA << 'X' << RESET;
          }
          else if (map[i][j] == BATT) {
            cout << YELLOW << map[i][j] << RESET;
          }
          else if (map[i][j] == WALL) {
            cout << RED << map[i][j] << RESET;
          }
          else {
            cout << map[i][j];
          }
        }
        cout << endl;
      }
      cout << endl;
    }
    
    int play(bool last_gen) {
      bool alive = true;

      if (last_gen) {
        cout << "\nDISPLAYING ROOMBA FROM THE LAST GEN" << endl;  // OPTIONAL
        // chrono::milliseconds timespan(1500);
        // this_thread::sleep_for(timespan);
      }

      make_map();

      do {
        if (energy == 0) {
          // dead roomba
          alive = false;
          // announce death
          if (last_gen) {
            cout << "\nROOMBA DIED" << endl;  // OPTIONAL
            chrono::milliseconds timespan(1500);
            this_thread::sleep_for(timespan);
          }
        }
        else {
          move(last_gen);
          if (last_gen) {
            show_map();  // OPTIONAL
            chrono::milliseconds timespan(250);
            this_thread::sleep_for(timespan);
          }
        }
      } while (alive);

      if (last_gen) {
        // cout << "\nFitness: " << score << endl;
        // chrono::milliseconds timespan(2000);
        // this_thread::sleep_for(timespan);
      }

      return score;
    }

    // collect battery
    void collect_batt() {
      if (map[y_pos][x_pos] == BATT) {
        energy += 5;
        map[y_pos][x_pos] = OPEN;

        // if (last_gen) {
        //   cout << "COLLECTED BATTERY" << endl;  // OPTIONAL
        // }
      }
    }

    void move(bool last_gen) {
      int action = -1;  // specific to function so that action resets with each move

      if (score == 0) {
        do {
          // provide a starting position in the playable area
          y_pos = (rand() % (MAP_SIZE - 2) + 1);
          x_pos = (rand() % (MAP_SIZE - 2) + 1);
        } while (map[y_pos][x_pos] == WALL);  // dont start on a wall


        // collect battery if standing on one
        collect_batt();

        if (last_gen) {
          show_map();
        }
      }

      scan();
      action = compare(last_gen);

      if (sensor[action] == WALL) {
        // OPTIONAL: PENALIZE RUNNING INTO WALLS 
        // this normalizes the data so that fitness is no longer 5 step increments.
        // also incentivizes bots to learn to move away from walls.
        score -= PENALTY;

        // if (last_gen) {
        //   cout << "HIT WALL." << endl;  // OPTIONAL
        // }
        ;
      }
      else {
        // move
        switch (action) {
          case NORTH: {
            y_pos -= 1;
            // if (last_gen) {
            //   cout << "WENT NORTH." << endl;  // optional
            // }
            break;
          }
          case EAST: {
            x_pos += 1;
            // if (last_gen) {
            //   cout << "WENT EAST." << endl;  // optional
            // }
            break;
          }
          case SOUTH: {
            y_pos += 1;
            // if (last_gen) {
            //   cout << "WENT SOUTH." << endl;  // optional
            // }
            break;
          }
          case WEST: {
            x_pos -= 1;
            // if (last_gen) {
            //   cout << "WENT WEST." << endl;  // optional
            // }
            break;
          }
        }
      }
      // remove energy each move
      energy--;

      // add to score
      score++;

      // collect battery if standing on one
      collect_batt();

      if (last_gen) {
        cout << "Score: " << score << endl;  // optional
        cout << "Energy: " << energy << endl;  // optional
      }
    }

    // last_gen -> keeps track of whether it's the last generation.
    // allows us to display movements for only the last generation.
    int compare(bool last_gen) {
      int action = -1;
      bool checking = true;
      bool match = true;

      int trait = 0;

      do {
        match = true;
        for (int i = 0; i < 4; i++) {
          if (gene[trait][i] != sensor[i] && gene[trait][i] != DONUT) {
            match = false;
          }
        }
        if (match) {
          action = gene[trait][4];
          checking = false;
        }
        else if (trait == 15) {
          action = gene[trait][4];
          checking = false;
        }
        trait++;  // counter which goes through each gene until match or nothing left
      } while (checking);

      if (action == RAND) {
        // fill action with a random direction
        action = (rand() % 4);

        if (last_gen) {
          cout << "DOING SOMETHING RANDOM" << endl;  // OPTIONAL
        }
      }
      else if (last_gen) {
        cout << "PLANNING" << endl;  // OPTIONAL
      }
      return action;
    }

    void scan() {
      sensor[NORTH] = map[y_pos - 1][x_pos];
      sensor[EAST] = map[y_pos][x_pos + 1];
      sensor[SOUTH] = map[y_pos + 1][x_pos];
      sensor[WEST] = map[y_pos][x_pos - 1];
    }

    int get_DNA(int i, int j) {
      return gene[i][j];
    }

    void set_DNA(Roomba mom, Roomba dad) {
      int num = -1;

      // mom gives first half 
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 5; j++) {
          // mutation
          num = rand() % 20;  // 5% mutation chance
          if (num == 0) {
            if (j == 4) {
              gene[i][j] = rand() % 5;  // input mutation into action slot
            }
            else {
              gene[i][j] = rand() % 4;  // input mutation into sensory slot
            }
          }
          else {
            gene[i][j] = mom.get_DNA(i,j);
          }
        }
      }

      // dad gives last half
      for (int i = 8; i < 16; i++) {
        for (int j = 0; j < 5; j++) {
          num = rand() % 20;
          // mutation
          if (num == 0) {
            if (j == 4) {
              gene[i][j] = rand() % 5;  // input mutation into action slot
            }
            else {
              gene[i][j] = rand() % 4;  // input mutation into trait slot
            }
          }
          else {
            gene[i][j] = dad.get_DNA(i,j);
          }
        }
      }
    }

    void reset() {
      energy = 5;
      score = 0;
      batt_count = 0;
      percentage = 0;
      x_pos = 0;
      y_pos = 0;
      wall_count = 0;
    }
};


void programGreeting();
void swap(int *, int *);
void bubbleSort(int *, int, int *);
void reproduce(Roomba *, int n);


int main() {
  int score = 0;
  double pop_fit;
  double overall_fit[GENS];
  bool last_gen = false;

  Roomba* bots = new Roomba[TOT_BOTS]; 
  Roomba* temp = new Roomba[TOT_BOTS];

  int scores[TOT_BOTS];
  int indexes[TOT_BOTS];

  srand(time(0));

  // program start

  programGreeting();

  for (int p = 0; p < GENS; p++) {
    for (int i = 0; i < TOT_BOTS; i++) {
      if (p == GENS - 1 && i == TOT_BOTS - SHOW_ROB) {
        last_gen = true;
      }
      
      // run each roomba in the generation through the game
      score = bots[i].play(last_gen);

      // store the scores & indexes in parallel arrays
      scores[i] = score;
      indexes[i] = i;
      pop_fit += score / (TOT_BOTS * 1.0);  // multiply by float so that division stores float
    }

    // sort indexes and scores from highest to lowest
    // sorted scores[] could be used for something later but is unused right now
    bubbleSort(scores, TOT_BOTS, indexes);

    // sort temp array 
    for (int i = 0; i < TOT_BOTS; i++) {
      temp[i] = bots[indexes[i]];
    }

    // sort bots array
    for (int i = 0; i < TOT_BOTS; i++) {
      bots[i] = temp[i];
      // cout << "Gen " << p << ". Bot " << i << ". " << "Score = " << bots[i].score << endl;  // debugger
    }

    // reproduction
    reproduce(bots, TOT_BOTS);

    // store population fitness
    overall_fit[p] = pop_fit;

    cout << "Gen " << p + 1 << " fitness: " << pop_fit << endl;  // optional display

    // reset variables in main() and in bots[]
    for (int i = 0; i < TOT_BOTS; i++) {
      bots[i].reset();
    }
    pop_fit = 0.0;
  }

  cout << "\nDisplaying avg fitness over time...\n" << endl;
  for (int i = 0; i < GENS; i++) {
    cout << "Gen " << i + 1 << " - " << overall_fit[i] << endl;
  }

  delete [] temp;  // when done
  temp = nullptr;
  delete [] bots;
  bots = nullptr;
}


void reproduce(Roomba bots[], int n) {
  int half = (n / 2);  // int div cause we want truncation

  for (int i = half; i < n; i++) {
    // first half mom + last half dad.
    if (i % 2) {
      bots[i].set_DNA(bots[i-half-1], bots[i-half]);
    }
    // first half dad + last half mom.
    else {
      bots[i].set_DNA(bots[i-half], bots[i-half-1]);
    }
  }
}


void programGreeting() {
  time_t now = time(0);
  tm *today = localtime(&now);

  cout << "Welcome to my program, here we will model evolution." << endl;
  cout << "Today's date: " << 1 + today->tm_mon << "/" << today->tm_mday
       << "/" << 1900 + today->tm_year << endl;
  cout << "-Brandon Montez.\n" << endl;
}


void bubbleSort(int arr[], int n, int ind[]) {
  for (int i = 0; i < n - 1; i++)    
    for (int j = 0; j < n - i - 1; j++)
      if (arr[j] < arr[j+1]) {
        swap(&arr[j], &arr[j+1]);
        swap(&ind[j], &ind[j+1]);
      }
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}