using namespace std;

int main(int argc, char **argv) {

	fstream fp;
	fp.open(argv[1],ios::in);
	
	
	fstream f;
	f.open(argv[2],ios::out);
	
	char ch;
	
	
	while(!fp.eof()){
		fp>>ch;
		if(!fp.eof())
		f<<ch;
	}
	
	
	return 0;
}