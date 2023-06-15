#include <iostream>
#include <vector>
#include <array>

using namespace std;

//per vedere altri metodi: 
// https://www.geeksforgeeks.org/vector-in-cpp-stl/

ostream& operator<<(ostream& os, const vector<int>& v)
{
    for (auto i = v.begin(); i != v.end(); i++)
        os << *i << " ";

    // for (int i = 0; i < v.size(); i++)
    //     os << v[i] << " ";
    // for (auto i : v)
    //     os << i << " ";
    return os;
}

void PrintSizeCapacity(const vector<int>& v)
{
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
}

template <typename T>
vector<T> GetVector(int n)
{
    vector<T> v;

    for (T i = 0; i < n; i++)
        v.push_back(i);
    return v;
}

int main()
{
    vector<int> v;

    int n = 4;
    for(int i=0; i<n; i++)
        v.push_back(i);

    cout << v[0] << endl;
    cout << v.at(0) << endl;
    cout << v.front() << endl;

    cout << endl;
	// provare auto
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}

    cout << string(2, '\n' );
    PrintSizeCapacity(v);

    cout << string(2, '\n' );
    cout << "resize to 1" << endl;
    v.resize(1);

    PrintSizeCapacity(v);
    cout << v << endl;

    v.shrink_to_fit();
    PrintSizeCapacity(v);

    cout << "is empty: " << v.empty() << endl;

    v = GetVector<int>(10);

    cout << v << endl;

    v.pop_back();
    cout << v << endl;

    v.insert(v.begin()+3,-1);
    cout << v << endl;
    
    v.erase(v.begin()+3);
    cout << v << endl;

    v.clear();
    
    return 0;
}