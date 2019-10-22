#include <iostream>
#include <fstream>
#include <cstdlib>
#include "queue.h"
#include "list.h"

using namespace std;

void printWord(string);
void GenLadder(int, int);
int hammingDist(string, string);
int sequentialSearch(string[], int, string);

//string words[5757];

struct wordstruct{
    int index;
    string w;

    LinearList<int> ham;
};
wordstruct w[5757];

void printWord(string &s) {
    cout << s << endl;
}

void GenLadder(int w1, int w2){
    Queue<int> q;
    LinearList<string> S;
    int windex, v;

    //clear s
    S.clear();

    //add w2 to a queue Q
    q.enqueue(w2);

    while(!q.isEmpty()){
        windex = q.dequeue();

        //for each word v in w.list do
            //if v.ptr = NULL and v ≠ w2 then
                //v.ptr <- w
                //enqueue v in Q
            //end if
        //end for
    //end while

        for(int i = 0; i < w[windex].ham.size(); i++){
            v = w[windex].ham[i];
            if(w[v].index == -1 && v != w2){
                w[v].index = windex;
                q.enqueue(v);
            }
        }

    }

    //if w1.ptr ≠ NULL then
        //append w1 to S
        //w <- w1.ptr
    if(w[w1].index != -1){
        S.insert(0,w[w1].w);
        windex = w[w1].index;

            //while w ≠ NULL do
                //append w to S
                //w <- w.ptr
            //end while
        //end if
        while(windex != -1){
            S.insert(0, w[windex].w);
            windex = w[windex].index;
        }
    }

S.traverse(printWord);
//end procedure
}

int hammingDist(string w1, string w2){
    int counter = 0;

    for(int i = 0; i < 5; i++){
        if(w1[i] != w2[i]){
            counter++;
            }
    }
    return counter;
}

int sequentialSearch(string[], int, string)
{
	return 0;
}

int sequentialSearch(wordstruct w[], int size, string wkey){
    int i = 0;
    while (i < size && w[i].w != wkey){
        i++;
    }

    if(i < size)
        return i;
    else
        return -1;
}

int main(void){
    ifstream infile;
    string w1, w2;
    int w1index, w2index, counter;
    LinearList<int> w1list;
    LinearList<int> w2list;

    infile.open("sgb-words.txt");

    if(!infile){
        cout<<"Unable to open file";
        exit(1);
    }

    for(int i = 0; i < 5757; i++){
        infile >> w[i].w;
        w[i].index = -1;
    }

    cout<<"Enter in the first word: ";
    cin>>w1;
    w1index = sequentialSearch(w, 5757, w1);
    if(w1index == -1){
        cout<<"That word is not in the list";
        return 0;
    }

    cout<<" "<<endl;

    cout<<"Enter in the second word: ";
    cin>>w2;
    w2index = sequentialSearch(w, 5757, w2);
    if(w2index == -1){
        cout<<"That word is not in the list";
        return 0;
    }

    for(int i = 0; i < 5756; i++){
        for(int j = i + 1; j < 5757; j++){
            if(hammingDist(w[i].w, w[j].w) == 1){
                    w[i].ham.insert(0, j);
                    w[j].ham.insert(0, i);
            }
        }
    }

   GenLadder(w1index, w2index);

    return 0;
}
