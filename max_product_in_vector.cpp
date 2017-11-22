#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(8);
    vec.push_back(6);
    vec.push_back(10);
    vec.push_back(9);
    vec.push_back(0);
    if (vec.size() < 2) {
        std::cout << "Not enough elements" << std::endl;
        return -1;
    }
    int max_value1 = 0;
    int max_value2 = 0;
    int min_value1 = vec[0];
    int min_value2 = vec[0];
    int size = vec.size();
    for (int ix = 0, jx = ix - size + 1; ix < size , jx < size; ++ix, ++jx) {
        if (ix < size) { 
            max_value1 = (vec[ix] > max_value1) ? vec[ix] : max_value1;
            min_value1 = (vec[ix] < min_value1) ? vec[ix] : min_value1;       
        }
        if (jx > 0) {
            max_value2 = ((vec[jx] > max_value2 ) && (vec[jx] != max_value1)) ? vec[jx] : max_value2;
            min_value2 = ((vec[jx] < min_value2 ) && (vec[jx] != min_value1)) ? vec[jx] : min_value2;
        }   
    }
    long long product = 0;
    if ((max_value1 * max_value2) > (min_value1 * min_value2)) {
      product  = (long long) max_value1 * (long long) max_value2;
    } else product = min_value1 * min_value2;
    std::cout << "Max1 number : " << max_value1 << std::endl << "Max2 number : " << max_value2 << std::endl;
    std::cout << "Min1 number : " << min_value1 << std::endl << "Min2 number : " << min_value2 << std::endl;
    std::cout << "Max product : " << product << std::endl;
}

