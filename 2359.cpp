#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        map<int, int> node1visited;
        map<int, int> node2visited;

        int node1cur = node1;
        int node2cur = node2;
        int currHop = 0;

        while (
            node1cur != -1 && 
            node2cur != -1)
        {
            if (node1visited.find(node1cur) != node1visited.end())
            {
                break;
            }
            node1visited[node1cur] = currHop;
            node1cur = edges[node1cur];
            currHop ++;

            if (node2visited.find(node2cur) != node2visited.end())
            {
                break;
            }
            node2visited[node2cur] = currHop;
            node2cur = edges[node2cur];
            currHop ++;
        }

    }
};