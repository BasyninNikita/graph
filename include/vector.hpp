#include <iostream>
#include <algorithm>
#include <cassert>
#include<vector>
template <typename T>
class graph
{
private:
	unsigned N;
  	bool** graph_;
public:
	graph()
	{
		N=0;
		graph_=nullptr;
	}
	graph(unsigned numb)
	{
		N=numb;
		graph_=new bool  *[N];
		for (unsigned i=0;i<N;++i)
		{
			graph_[i]=new bool[N];
		}
	}
	void read(std::istringstream& stream) {
    		for (unsigned i = 0; i < N; i++) {
      			for (unsigned j = 0; j < N; j++) {
        			stream >> graph_[i][j];
      			}
    		}
  	}
	
