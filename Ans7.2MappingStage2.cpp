
#define FILENAME "C:\\Users\\Liam\\Downloads\\gibrish.bin"
int main()
{
 HANDLE hFile;

 LPCSTR pFileName = FILENAME;
 DWORD numOfAChars = 0;
 hFile = CreateFileA(pFileName,GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
 DWORD file_size = GetFileSize(hFile, NULL);
//LPVOID pBuf;
//LPSTR data;
// pBuf = malloc(file_size + 1);
// ReadFile(hFile, pBuf, file_size, NULL, NULL);
// data = (LPSTR)pBuf;
 SYSTEM_INFO sys_info;
 GetSystemInfo(&sys_info);
 int mem_buffer_size = sys_info.dwAllocationGranularity;
 HANDLE hMapFile = CreateFileMappingA(hFile, NULL, PAGE_READONLY,0,0,NULL);
 DWORD chunks = 0;	

 while (chunks <= file_size - mem_buffer_size) {
	 LPVOID lpView = MapViewOfFile(hMapFile, FILE_MAP_READ, 0, chunks, mem_buffer_size);
	 chunks += 65536;
	 char* p = (char*)lpView;
	 for (DWORD i = 0; i < 65536; i++) {
		 if(p[i] == 'A')
		 {
			 numOfAChars++;
		 }
	 }
	 printf("Number of 'A' characters: %lu\n", numOfAChars);
	 UnmapViewOfFile(hFile);
 }
 int remaining_bytes = file_size - chunks;
 LPVOID lpView = MapViewOfFile(hMapFile, FILE_MAP_READ, 0, chunks, remaining_bytes);
 char* p = (char*)lpView;
 for (DWORD i = 0; i < 65536; i++) {
	 if (p[i] == 'A')
	 {
		 numOfAChars++;
	 }
 }
 UnmapViewOfFile(hFile);
 printf("Number of 'A' characters1: %lu\n", numOfAChars);

 // UnmapViewOfFile(pBuf);
 CloseHandle(hMapFile);
// free(pBuf);
 CloseHandle(hFile);
 return 0;
}
