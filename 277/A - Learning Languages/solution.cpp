#include <bits/stdc++.h>
using namespace std;
 
int parent[105];
 
int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}
 
// Returns true if a new merge actually happened
bool union_sets(int a, int b) {
    a = find_set(a); b = find_set(b);
    if (a != b) {
        parent[b] = a;
        return true; 
    }
    return false; // Skipped because they already share a parent
}
 
int main() {
    int ne, nl;
    cin >> ne >> nl;
 
    for (int i = 1; i <= nl; i++) parent[i] = i;
 
    int zero_lang_employees = 0;
    int successful_merges = 0;
    
    // Track unique languages across the entire company
    set<int> unique_languages_spoken; 
 
    for (int i = 0; i < ne; i++) {
        int limit;
        cin >> limit;
        if (limit == 0) {
            zero_lang_employees++;
            continue;
        }
        int first_lang;
        cin >> first_lang;
        unique_languages_spoken.insert(first_lang);
        
        for (int j = 1; j < limit; j++) {
            int next_lang;
            cin >> next_lang;
            unique_languages_spoken.insert(next_lang);
            
            if (union_sets(first_lang, next_lang)) {
                successful_merges++;
            }
        }
    }
 
    // Edge case: If absolutely nobody knows any language
    if (zero_lang_employees == ne) {
        cout << ne << "
";
        return 0;
    }
 
    // Active components = (Total languages spoken) - (Successful merges)
    int active_components = unique_languages_spoken.size() - successful_merges;
 
    // Final Answer
    int ans = (active_components - 1) + zero_lang_employees;
    cout << ans << "
";
 
    return 0;
}