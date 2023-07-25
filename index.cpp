
// #include <iostream>

// #include <cstring>


// int main(){
    
//     size_t newLength = 5;
//     char* newData = new (std::nothrow) char[newLength + 1]; // Use 'nothrow' to avoid exceptions on allocation failure
//     // std::cout<<"hello";
//     std::cout<<strlen(newData)<<'\n';
//     if (newData) {
//         std::memcpy(newData, , length);             // Copy the first part of the data
//         std::memcpy(newData + length, other.data, other.length); // Copy the second part of the data

//         newData[newLength] = '\0'; // Null-terminate the new string

//         delete[] data; // Deallocate the old data
//         data = newData;
//         length = newLength;
//     return 0;
// }