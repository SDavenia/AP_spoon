/*BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
int result;

for(int i=0;i<N;i++){
   result=calculate_result();//valid function defined somewhere else
   std::ofstream filevar("results.txt");
   filevar<<result<<std::endl;
   filvar.close();
}
*/

// This code is bad as we create and erase the same file until N
// But we overwrite it everytime so we end up with a file containing only
// The last number N

/*
int result;
std::ofstream filevar("results.txt");

for(int i=0;i<N;i++){
   result=calculate_result();//valid function defined somewhere else
   filevar<<result<<std::endl;
}
filvar.close();
*/
