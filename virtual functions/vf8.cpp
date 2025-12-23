#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class horse {
protected:
    string name;
    float position;
public:
    horse(string n) : name(n), position(0.0f) {}
    virtual void horse_tick() { position += (rand() % 5 + 1) * 0.1f; }
    float get_position() const { return position; }
    string get_name() const { return name; }
    virtual ~horse() {}
};

class comhorse : public horse {
public:
    comhorse(string n) : horse(n) {}
    void horse_tick(horse* hArray[], int num) {
        float max_pos = position;
        int leader_index = -1;
        for (int i = 0; i < num; i++) {
            if (hArray[i]->get_position() > max_pos) {
                max_pos = hArray[i]->get_position();
                leader_index = i;
            }
        }
        position += (rand() % 5 + 1) * 0.1f;
        if (leader_index >= 0 && position >= max_pos - 0.1f) {
            position += 0.1f + (rand() % 2) * 0.05f;
        }
    }
};

class comtrack {
    comhorse* hArray[5];
    int num_horses;
public:
    comtrack() : num_horses(0) {}
    void add_horse(comhorse* h) {
        if (num_horses < 5)
            hArray[num_horses++] = h;
    }
    void race() {
        bool finished = false;
        while (!finished) {
            finished = false;
            for (int i = 0; i < num_horses; i++) {
                hArray[i]->horse_tick((horse**)hArray, num_horses);
            }
            for (int i = 0; i < num_horses; i++) {
                cout << hArray[i]->get_name() << ": " << hArray[i]->get_position() << " ";
            }
            cout << endl;
            for (int i = 0; i < num_horses; i++) {
                if (hArray[i]->get_position() >= 10.0f) finished = true;
            }
        }
        cout << "Race finished!\n";
        for (int i = 0; i < num_horses; i++)
            cout << hArray[i]->get_name() << " final position: " << hArray[i]->get_position() << endl;
    }
};

int main() {
    srand(time(0));
    comtrack track;
    comhorse* h1 = new comhorse("Thunder");
    comhorse* h2 = new comhorse("Lightning");
    comhorse* h3 = new comhorse("Blaze");

    track.add_horse(h1);
    track.add_horse(h2);
    track.add_horse(h3);

    track.race();

    delete h1;
    delete h2;
    delete h3;

    return 0;
}
