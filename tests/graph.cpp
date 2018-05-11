#include <catch.hpp>
#include <sstream>

#include "graph.hpp"
TEST_CASE("just a test")
{
  std::string in{
     		"0 1 0 0 \n"
		"0 0 1 0 \n"
		"0 0 0 1 \n"
		"1 0 0 0 \n"
   };
graph_t graph(4);
std::istringstream stream(in);
graph.read(stream);
std::vector<unsigned> result;
result = graph.dfs(1);
std::ostringstream output;
graph.print(output, result);
std::string out = "2 3 4 1 ";
REQUIRE( out == output.str() );
}
TEST_CASE("exept1")
{
	try{
		std::string in{
     		"0 2 0 0 \n"
		"0 0 1 0 \n"
		"0 0 0 1 \n"
		"1 0 0 0 \n"
   		};
		graph_t graph(4);
		std::istringstream stream(in);
		graph.read(stream);
	}
	bool a=false;
	catch (std::invalid_argument)
	{
		a = true;
	}
REQUIRE(a==true)
}
TEST_CASE("exept2")
{
	try{
		std::string in{
     		"0 1 0 0 \n"
		"0 0 1 0 \n"
		"0 0 1 1 \n"
		"1 0 0 0 \n"
   		};
		graph_t graph(4);
		std::istringstream stream(in);
		graph.read(stream);
	}
	bool a=false;
	catch (std::invalid_argument)
	{
		a = true;
	}
REQUIRE(a==true)
}
