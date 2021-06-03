//Function to find a sub-array which adds up to a given sum s
vector<int> subarraySum(int arr[], int n, int s)
{
  int count;
  int l=0,r=0;
  vector<int> k; //stores the result(l,r) in an array
  count = 0; //currentSum
  while(r<=n)
  {
    if(count==s)
    {
      k.push_back(l+1);
      k.push_back(r);
      return k;
    }
    if(count<s)
    {
      r++;
      count+=arr[r-1];
    }
    if(count>s)
    {
      count-=arr[l];
      l++;
      continue;
    }
  }
  k.push_back(-1);
  return k;
}
