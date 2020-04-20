#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long result = 0;
    int n = numbers.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if(((long long)numbers[i]) * numbers[j] > result) {
                result = ((long long)numbers[i]) * numbers[j];
                    
            }
            
        }
    }

    return result;
}

long long MaxPairwiseProductFast(const std::vector<int> & numbers) {
    int n = numbers.size();

    int max_index1 = -1;
    for(int i = 0; i < n; ++i)
        if((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
            max_index1 = i;

    int max_index2 = -1;
    for(int j = 0; j < n; ++j)
        if((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
            max_index2 = j;

    //std::cout << max_index1 << ' ' << max_index2 << "\n";

    return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main() {
    while(true){
        int n = rand()%100+2;
        std::cout << n << "\n";
        std::vector<int> a;

        for(int i=0;i<n;++i){
            a.push_back(rand()%100000);
        }
        for(int i=0;i<n;++i){ 
            std::cout<<a[i]<<' ';
        }
        std::cout<<"\n";
        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProductFast(a);
        if(res1!=res2){
            std::cout << "wrong answer:" <<res1 <<' ' << res2<<"\n";
            break;
        }
        else{
            std::cout<<"OK\n";
        }
    } 


    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long long max_product = MaxPairwiseProduct(numbers); 
    std::cout << max_product << "\n";
    return 0;
}
