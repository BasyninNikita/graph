#include <catch.hpp>
#include <sstream>

#include "graph.hpp"
TEST_CASE("just a test")
{
  std::string in{"0 1 0 0 1\n"
     "1 0 1 0 1\n"   
     "1 1 0 0 1\n"
     "1 1 1 0 1\n"
     "0 1 0 0 0\n"
   };
graph graph(5);
std::istringstream stream(in);
graph.read(stream);
std::vector<unsigned> result;
std::vector<unsigned> result1;
result = graph.dfs(1);
result1 = graph.dfs(3);
std::ostringstream output;
std::ostringstream output1;
graph.print(output, result);
graph.print(output1, result1);
std::string out = "2 5 1 3 5 1 2 5 1 2 3 5 2 ";
std::string out1 = "1 2 5 1 2 3 5 2";
REQUIRE( out == output.str() );
REQUIRE( out1 == output1.str() );
}

