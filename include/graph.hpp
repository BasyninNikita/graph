#include <iostream>
#include <sstream>
#include <vector>
#include<string>
#include<stdexcept>
class graph_t
{
private:
	unsigned N;
  	bool** graph_;
public:
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
      			    unsigned k;
        		    if(stream >>k){
				        if((k!=0)&&(k!=1)) throw std::invalid_argument("Incorrect numeral");}
				        graph_[i][j]=k;
      			    }
			        if(graph_[i][i]!=0) throw std::invalid_argument("diagonal element=1");	   
    		    }
  	}
	std::vector<unsigned>dfs(unsigned index)
	{
		std::vector<unsigned> result,ch;
		for(unsigned i=0;i<N;++i){ch.push_back(false);}
		help(index,ch,result);
		return result;
	}
	graph_t & operator=(graph_t const &) = delete;
private:
	void help(unsigned index,std::vector<unsigned> & ch,std::vector<unsigned> & result)
	{
		ch[index] = true;
    		result.push_back(index + 1);
    		for (unsigned i = 0; i < N; i++) {
      			if (graph_[index][i]) {
        			if (!(ch[i])) {
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
	void print(std::ostream& ostream, std::vector<unsigned> result);
};
void graph_t::print(std::ostream& ostream, std::vector<unsigned> result) {
    		for (unsigned i : result) {
      			ostream << i << ' ';
    		}
	}
