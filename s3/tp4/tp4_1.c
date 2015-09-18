char * miroir (const char *s){
	int len=0;
	while(s[len] != '\0')
		len++;
	char ans[len];
	int i=0;
	while(s[i] != '\0'){
		ans[i] = s[len-i];
		i++;
	}
	ans[++i]='\0';
	return &ans;
}
