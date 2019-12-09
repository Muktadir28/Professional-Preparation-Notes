/*

----------------Trie with arry------------------
----Trie for all upper and lower case later-----

*/

#include <bits/stdc++.h>
#define MX 100005

using namespace std;

int get_value_of_char(char ch){
    if(ch<95) return (int) (ch - 'A');
    return (int) (ch - 'a' + 26);
}

struct node{
    int next[52];
    int word_cnt; /// here word cnt is counting how many words ends at this point
    void set(){
        word_cnt = 0;
        for(int i=0;i<=53;i++){
            next[i] = 0;
        }
    }
}trie[MX];

int new_element = 0;

void insert(char *str){
    int i, val, x=0;
    for(i=0;str[i];i++){
        if(str[i]==' ') continue;
        val = get_value_of_char(str[i]);
        /// If the chain is not exists
        /// allocating memory by new_element++ that means new array element
        if(!trie[x].next[val]){
            ///putting next arrays position at recent array's linked part
            trie[x].next[val] = new_element++;
            trie[new_element-1].set();
        }
        x = trie[x].next[val];
    }
    ///marking last element as last
    trie[x].word_cnt++;
}


int search(char *str){
    int i, val,x=0;
    for(i=0;str[i];i++){
        if(str[i]==' ')continue;
        val = get_value_of_char(str[i]);
        ///if query element not exists then returning false
        if(!trie[x].next[val]) return 0;
        x = trie[x].next[val];
    }
    /// returning how many elements like "str"
    return trie[x].word_cnt;
}
