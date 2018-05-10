#include <iostream>
#include <algorithm>
#include <cassert>
#include<vector>
template <typename T>
class graph_t
{
private:
	unsigned N;
  	bool** graph_;
public:
	graph_t()
	{
		N=0;
		graph_=nullptr;
	}
	graph_t(unsigned numb)
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
	std::vector<unsigned>dfs(unsigned index)
	{
		std::vector<unsigned> result,ch;
		for(unsigned i=0;i<N;++i){ch.push_back(false);}
		help(index,ch,result);
		return result;
	}
private:
	void help(unsigned index,std::vector<unsigned> * ch,std::vector<unsigned> * result)
	{
		(*ch)[index] = true;
    		(*result).push_back(index + 1);
    		for (unsigned i = 0; i < N; i++) {
      			if (graph_[index][i]) {
        			if (!((*ch)[i])) {
          				help(i, ch, result);
        			}
      			}
    		}
	}
public:
	~graph_t()
	{
		for(unsigned i=0;i<N;++i)
			delete[]graph_[i];
		delete[]graph_;
	}
	void print(std::ostream& ostream, std::vector<unsigned> result) {
    		for (unsigned i : result) {
      			ostream << i << ' ';
    		}
	}
};
