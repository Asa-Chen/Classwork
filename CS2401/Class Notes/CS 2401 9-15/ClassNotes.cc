//Relevant to Lab 3
//Going off of last class session notes concerning pointers
//Dynamic Arrays
int* data;
data = new int[4];

for (int i = 0; i < 4; i++){//shuffles through array
    //data + i = address data is storing + (i*sizeof(int))
    //*(data + i) is saying, "take the address of the first index, and move  the pointer to the next array location by adding the size of an int to the address"
    //*(data + i) = (i + 1) * 5; //This is the hard way
    data[i] = (i+5)*5; //This does the same thing, but easier
}

for (int i = 0; i < 4; i++){
    //cout << *(data+i) << endl; //This is the hard way
    cout << data[i] << endl;
}

delete data;