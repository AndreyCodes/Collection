#include <iostream>
#include <vector>
#include <windows.h>
#include<tuple>
#include<list>


template<typename... Args>
struct zip
{
    
    zip(const Args&... args): m_data{std::make_tuple(args...)}{}
    std::tuple<Args...> m_data;

    constexpr static std::size_t size = std::tuple_size_v<decltype(m_data)>;

    template<int idx = 0>
    void iter_all()
    {
        if constexpr(idx <= size-1)
        {
            auto& val = std::get<idx>(m_data);
            for(auto& el: val)3
            {
                std::cout << el;
            }
            iter_all<idx+1>();
        }
    }
};

int main()
{
    std::vector<int> vec{1,2,3};
    std::list<int> lis{1,3,5};

    zip z{vec,lis};
    z.iter_all();
}
