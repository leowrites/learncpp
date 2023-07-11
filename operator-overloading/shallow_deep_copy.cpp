// default copy constructor and assignment op are shallow copies

// when working with dynamic memory, shallow copy can be dangerous since
// shallow copy only copies address of pointer, if the allocated memory at that address
// is freed, all other pointers will be dangling

// to deal with this, we should make deep copy which allocates separate memories
