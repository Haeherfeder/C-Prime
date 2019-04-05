// Überprüfung ob n eine Primzahl ist
// Nutzung des Integers als Boolean (0: false, 1: true)
int is_prime(int n);

// Gibt die nächst höhere Primzahl zurück
int next_prime(int n);

// wie next_prime, funktioniert nur, wenn n ungerade und größer 2
// existiert aus Performance-Gründen
int next_prime_unsafe(int n);
