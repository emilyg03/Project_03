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

// Load dictionary into a map of word lengths
void loadDictionary(const string& filename, unordered_map<int, unordered_set<string>>& dictionary) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }

    string word;
    while (file >> word) {
        dictionary[word.size()].insert(word);
    }

    file.close();
}

// Generate all possible neighbors for a word
vector<string> getNeighbors(const string& word, const unordered_set<string>& dict) {
    vector<string> neighbors;
    string temp = word;

    for (size_t i = 0; i < word.size(); ++i) {
        char originalChar = temp[i];
        for (char c = 'a'; c <= 'z'; ++c) {
            if (c == originalChar) continue;
            temp[i] = c;
            if (dict.find(temp) != dict.end()) {
                neighbors.push_back(temp);
            }
        }
        temp[i] = originalChar; // Restore original character
    }

    return neighbors;
}

// BFS to find the shortest word ladder
bool findWordLadder(const string& start, const string& end, 
                    const unordered_map<int, unordered_set<string>>& dictionary, vector<string>& ladder) {
    if (start.size() != end.size() || dictionary.find(start.size()) == dictionary.end()) {
        return false;
    }

    const auto& dict = dictionary.at(start.size());
    if (dict.find(start) == dict.end() || dict.find(end) == dict.end()) {
        return false;
    }

    unordered_map<string, string> parent; // To reconstruct the path
    queue<string> q;
    q.push(start);
    parent[start] = "";

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (current == end) {
            // Reconstruct the path
            string word = end;
            while (!word.empty()) {
                ladder.push_back(word);
                word = parent[word];
            }
            reverse(ladder.begin(), ladder.end());
            return true;
        }

        for (const string& neighbor : getNeighbors(current, dict)) {
            if (parent.find(neighbor) == parent.end()) { // Not visited
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    return false; // No path found
}

int main() {
    unordered_map<int, unordered_set<string>> dictionary;
    loadDictionary("wordLadder_dictionary.txt", dictionary);

    string start, end;
    while (true) {
        cout << "Enter start word (or 'exit' to quit): ";
        cin >> start;
        if (start == "exit") break;

        cout << "Enter end word: ";
        cin >> end;

        // Convert to lowercase
        transform(start.begin(), start.end(), start.begin(), ::tolower);
        transform(end.begin(), end.end(), end.begin(), ::tolower);

        vector<string> ladder;
        if (findWordLadder(start, end, dictionary, ladder)) {
            cout << "Word Ladder: ";
            for (const string& word : ladder) {
                cout << word << " ";
            }
            cout << endl;
        } else {
            cout << "No word ladder found from " << start << " to " << end << "." << endl;
        }
    }

    return 0;
}
