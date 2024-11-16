#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
//organize by word length
// load dictionary 
void loadDictionary(const string& filename, unordered_map<int, unordered_set<string>>& dictionary) {
    ifstream file(filename);
    if (!file.is_open()) {                     // check if the file was opened
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }
// get word from file and input into set based on its length
    string word;
    while (file >> word) {
        dictionary[word.size()].insert(word);
    }

    file.close();              // close
}

// word neighbor generator
vector<string> getNeighbors(const string& word, const unordered_set<string>& dict) {
    vector<string> neighbors;          //store neighboring word
    string temp = word;

    for (size_t i = 0; i < word.size(); ++i) {
        char originalChar = temp[i];                 // store andsub each letter
        for (char c = 'a'; c <= 'z'; ++c) {
            if (c == originalChar) continue;        // same char     
            temp[i] = c;
            if (dict.find(temp) != dict.end()) {      // check dictionary for new word
                neighbors.push_back(temp);
            }
        }
        temp[i] = originalChar; // original character restoration
    }

    return neighbors;
}

// BFS -> shortest word ladder
bool findWordLadder(const string& start, const string& end, 
                    const unordered_map<int, unordered_set<string>>& dictionary, vector<string>& ladder) {
    if (start.size() != end.size() || dictionary.find(start.size()) == dictionary.end()) {            // same length check
        return false;
    }

    const auto& dict = dictionary.at(start.size());
    if (dict.find(start) == dict.end() || dict.find(end) == dict.end()) {
        return false;
    }

    unordered_map<string, string> parent; // reconstruct path map
    queue<string> q;
    q.push(start);
    parent[start] = "";

    while (!q.empty()) {              // get current word
        string current = q.front();
        q.pop();

        if (current == end) {      // word end
            // reconstruct path
            string word = end;
            while (!word.empty()) {
                ladder.push_back(word);
                word = parent[word];
            }
            reverse(ladder.begin(), ladder.end());
            return true;        //word ladder found
        }

        for (const string& neighbor : getNeighbors(current, dict)) {
            if (parent.find(neighbor) == parent.end()) { // not visited
                parent[neighbor] = current;
                q.push(neighbor);                 // queue
            }
        }
    }

    return false;                 // no ladder
}

int main() {
    unordered_map<int, unordered_set<string>> dictionary;
    loadDictionary("wordLadder_dictionary.txt", dictionary);

    string start, end;
    while (true) {
        cout << "Enter start word (or 'exit' to quit): ";
        cin >> start;
        if (start == "exit") break;         // exit program

        cout << "Enter end word: ";
        cin >> end;

        // convert to lowercase
        transform(start.begin(), start.end(), start.begin(), ::tolower);
        transform(end.begin(), end.end(), end.begin(), ::tolower);

         vector<string> ladder;        
        if (findWordLadder(start, end, dictionary, ladder)) {
            cout << "Word Ladder: ";
            for (const string& word : ladder) {
                cout << word << " ";
            }
            cout << endl;
            cout << "Length of ladder: " << ladder.size() << endl;              // length of the ladder
        } else {
            cout << "No word ladder found from " << start << " to " << end << "." << endl;
        }
    }

    return 0;
}