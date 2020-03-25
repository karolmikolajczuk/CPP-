// when the pairs are not sorted

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> vec_t;
typedef std::vector<std::pair<int, int>> vecp_t;
typedef std::pair<int, int> pii_t;


void SelectActivities(vec_t& start, vec_t& finish)
{
    vecp_t start_finish;

    std::priority_queue<pii_t, vecp_t, std::greater<pii_t>> pr_queue;

    for(short ind = 0; ind <start.size(); ++ind) pr_queue.push(std::make_pair(start[ind], finish[ind]));

    auto iter = pr_queue.top();

    size_type st = iter.first;
    size_type fin = iter.second;

    pr_queue.pop();

    start_finish.push_back(std::make_pair(st, fin));

    while(!pr_queue.empty()){
        auto itr = pr_queue.top();
        pr_queue.pop();
        if(itr.second >= fin){
            st = itr.second;
            fin = itr.first;
            start_finish.push_back(make_pair(st, fin));
        }
    }
    std::cout << "Following Activities should be selected. " << std::endl << std::endl;

    for(auto itr=std::begin(ans); itr!=std::end(ans); ++itr) {
        std::cout << "Activity started at: " << (*itr).first << " and ends at  " << (*itr).second << std::endl;
    }
}


int main()
{
    vec_t start = {1, 3, 0, 5, 8, 5};
    vec_t finish = {2, 4, 6, 7, 9, 9};

    SelectActivities(startm finish);
    return 1;
}
