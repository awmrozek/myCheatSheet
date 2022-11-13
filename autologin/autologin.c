// Program to auto log-in user on tty
int main () {
	execlp("login", "login", "-f", "welw", 0);
}
