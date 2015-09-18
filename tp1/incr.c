int incr(int t[8]){
	for (int i = 0; i < 8; ++i) {
		if (t[i] == 0){
			t[i] = 1;
			return 0;
		}else{
			t[i]=0;
		}
	}return -1;
}