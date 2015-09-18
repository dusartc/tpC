/*
 *int mon_strlen(char s[]){
 *        int ans=0;
 *        while(s[ans++]!='\0');
 *        return ans-1;
 *}
 */

int mon_strlen(const char *s){
	int ans=0;
	while(s[ans++] != '\0');
	return ans-1;
}
