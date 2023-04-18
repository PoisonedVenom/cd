#include <bits/stdc++.h>
using namespace std;

struct Production{
	char lhs;
	string rhs;

	Production(char lhs, string rhs) : lhs(lhs), rhs(rhs){}
};

struct CFG{
	char start_symbol;
	vector<Production> productions;

	CFG(char start_symbol, vector<Production> productions) :
	start_symbol(start_symbol), productions(productions){}
};

// Function to compute the first set of a non-terminal symbol

set<char> compute_first_set(char non_terminal, map<char, set<char>>& first_sets, CFG& gram) {
	 // Check if the first set for this non-terminal has already been computed
	 auto it = first_sets.find(non_terminal);
	 if(it != first_sets.end()) {
	 	return it->second;
	 } 

	 set<char> first_set;
	 for(auto& prod : gram.productions) {
	 	// For the productions whose lhs is given non_terminal
	 	if(prod.lhs == non_terminal) {
	 		// if fisrt character of rhs is terminal
	 		if(!isupper(prod.rhs[0])) {
	 			first_set.insert(prod.rhs[0]);
	 		}

	 		// if its non terminal compute its first and update
	 		else if(isupper(prod.rhs[0])) {
	 			set<char> sub_first_set = compute_first_set(prod.rhs[0], first_sets, gram);
	 			first_set.insert(sub_first_set.begin(), sub_first_set.end());
	 		} 

	 		// If the right-hand side is epsilon, add epsilon to the first set
	 		else if(prod.rhs == "#") {
	 			// string epsilon = "epsilon";
	 			char x = '#';
	 			first_set.insert(x);
	 		}
	 	}
	 }
	 first_sets[non_terminal] = first_set;
	 return first_set;
}

int main() {
// Example CFG: S -> aS | bA, A -> aS | bA | epsilon
CFG grammar('E', {
{'E', "TR"},
{'R', "+TR"},
{'R', "#"},
{'T', "FY"},
{'Y', "*FY"},
{'Y', "#"},
{'Y', "(E)"},
{'F', "i"}
});

// Compute the first set for each non-terminal symbol
map<char, set<char>> first_sets;
for (auto& prod : grammar.productions) {
    if (isupper(prod.lhs)) {
        compute_first_set(prod.lhs, first_sets, grammar);
    }
}

// Print the first sets
cout << "First sets:" << endl;
for (auto& entry : first_sets) {
    cout << entry.first << ": { ";
    for (auto& symbol : entry.second) {
        cout << symbol << " ";
    }
    cout << "}" << endl;
}

	return 0;
}