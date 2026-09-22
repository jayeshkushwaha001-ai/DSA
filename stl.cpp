#include <bits/stdc++.h>

using namespace std;

void pairss()
{
    pair<int, pair<int, int>> p = {1, {2, 3}};
    cout << p.second.second << endl;
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arr[1].second << endl;
}

// VECTORS
void vec()
{
    vector<int> v;
    v.push_back(1);
    // faster one
    v.emplace_back(2);

    vector<pair<int, int>> vecc;
    vecc.push_back({1, 2});
    vecc.emplace_back(3, 4);

    // v= {20 , 20 , 20};
    vector<int> v1(3, 20);
    vector<int> v2(v1);

    // cout << v1[0] << " " << v1.at(0) << endl;
    // Iterators
    // vector<int>::iterator it = v.begin();
    // // it++;
    // cout << *(it) << endl;

    // // end points outside the last element

    // vector<int>::iterator it2 = v.end();
    // cout<<v.back()<<endl;

    // vector<int>::iterator = auto
    for(auto it= v1.begin(); it!=v1.end(); it++){
        cout<<*(it)<< " ";
    }
    cout<<endl;

    for(auto it2:v1){
        cout<<it2<<endl;
    }

    // erase(start , end) => end will not remove 
    v1.erase(v1.begin() , v1.begin()+2);


    // INSERT
    vector<int> v3(2,100);
    v3.insert(v.begin() , 2);       //{2,100 ,100}
    v3.insert(v.begin() , 2, 10);   //{10 , 10 , 100 , 100}

    //  SIZE
    v3.size();

    //pop_back
    v3.pop_back();  //{10 , 10 , 100}

    // v1 -> {10 , 20}
    //v2 -> {30 , 40}
    v1.swap(v2);   // v1 = {30 , 40} , v2 = {10 , 20}
    
    v.clear();   //erases the entire vector

    cout<<v.empty()<<endl;
}

// LIST
void explainlist(){
    list<int> l;
    l.push_back(2);
    l.emplace_back(3);  // {2,3}
    l.push_front(5); //{5,2,3}
    l.emplace_front(); //{2,3}
    //rest fn same as vector like insert , clear , begin...
} 

// DEQUE
void explainDeque() {
    deque<int> dq;
    dq.push_back(2);
    dq.emplace_back(3);  // {2,3}
    dq.push_front(5); //{5,2,3}
    dq.emplace_front(); //{2,3}

    dq.pop_back();  //{2}
    dq.pop_front(); //{}
     //rest fn same as vector like insert , clear , begin...
}

// STACK
void explainStack(){
    stack<int> st;
    st.push(3);
    st.push(5);
    st.push(6);  // {6,5,3}
    st.emplace(7); //{7,6,5,3}

    cout<<st.top();  // 7
    st.pop();  // {6,5,3}
    cout<<st.size();
    stack<int> st1, st2;
    st1.swap(st2);
}

// QUEUE
void explainQueue(){
    queue<int> q;
    q.push(1);
    q.push(3);
    q.push(4);  //{1,3,4}
    q.back()+=5; // {1,3,9}
    cout<<q.front(); // 1
    q.pop(); // {3,9}
}

// priority queue = max heap
//NON LINEAR FASHION INSERT
// TOP = O(1) , PUSH , POP = O(logn)
void explainPQ(){
    priority_queue<int> pq;
    pq.push(1);
    pq.push(5);
    pq.push(6);  //{6,5,1}
    cout<<pq.top(); //6
    pq.pop();  //{5,1}

// MIN HEAP
    priority_queue<int, vector<int> , queue<int>> PQ;
    PQ.push(1);
    PQ.push(5);
    PQ.push(3);  //{1,3,5}
    PQ.pop(); //{3,5}

}

// SET : unique , sorted O(LOGN)
void explainSet(){
    set<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(4);
    s.insert(4); //{1,4,5}
//  if the element not present it  gives st.end()
    auto it  = s.find(3);
    cout<<*(it)<<endl;

    s.erase(4);  //{1,5}
    // s.erase(it);
    // s.erase(it , it+2);
}

// multiset : only sorted
void explainMultiset(){
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);  //{1,1,1,1}
    auto it = ms.find(3);
    ms.erase(1);  //erase all 1
}

// uNORDERED : UNIQUE ONLY
void explainUset(){
    unordered_set<int> us;
    // only upper & lower bound doesnot work , rest of all same as set;
}

//MAP - UNIQUE & SORTED KEY STORE IN KEY VAUE PAIR
void explainMap(){
    map<int , int> mpp;
    mpp[1] = 2; //key = 1 , value = 2
    mpp.insert({1,2});  //key = 1 , value = 2

    for(auto it :mpp){
        cout<<it.first << " : "<<it.second<<endl;
    }
    cout<<mpp[1];
    auto it1 = mpp.find(1);
}

// multimap : can store duplicate keys O(LOGN)
// unordered map : unique but unordered O(1)

// EXTRA in built functions
void extra(){
    int arr[] = {1,4,2,3,5};
    sort(arr , arr+5); // {1,2,3,4,5}
    sort(arr , arr+5 ,greater<int>()); //{5,4,3,2,1}

    // sort(a, a+n , comp)  comp = comparator, need to write function for this
    

    // NO. OF SET BITS 
    int num=7;
    int count = __builtin_popcount(num);  // 111 = 3
    long long no = 2345567;
    int cnt = __builtin_popcountll(no);

    // permutation of a no. in dictionary order
    string s = "321";
    sort(s.begin(), s.end()); // 123
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin() , s.end()));

    int max = *max_element(arr,arr+5);  // gives maximum element
}


int main()
{
    // vec();
    // explainSet();
    // pairss();
    return 0;
}