# Distributed File System Conceptual

A conceptual implementation of a distributed file system built in C++, demonstrating key principles and mechanisms used in modern distributed storage systems.

## Overview

This project implements a conceptual distributed file system that demonstrates how files can be stored, accessed, and managed across multiple nodes in a network. The implementation focuses on core distributed system concepts like replication, fault tolerance, consistency, and distributed coordination.

## Features

- **File Distribution**: Splits and distributes files across multiple storage nodes
- **Replication**: Maintains multiple copies of data for fault tolerance
- **Consistency Management**: Ensures data consistency across replicated nodes
- **Transparent Access**: Provides a unified view of the distributed storage
- **Fault Tolerance**: Handles node failures gracefully
- **Scalability**: Supports dynamic addition and removal of storage nodes
- **Directory Service**: Maintains metadata about file locations and attributes
- **Caching**: Implements caching mechanisms to improve performance

## System Architecture

The system consists of several key components:

1. **Client Interface**: Provides API for file operations (create, read, write, delete)
2. **Name Server**: Maintains the directory structure and file metadata
3. **Storage Nodes**: Store the actual file data
4. **Replication Manager**: Handles data replication across nodes
5. **Consistency Controller**: Ensures data consistency across replicas
6. **Fault Detector**: Identifies node failures and triggers recovery processes

## Requirements

- C++17 compatible compiler (GCC 7+, Clang 5+, or MSVC 2017+)
- CMake 3.10 or higher
- Boost libraries (for networking and serialization)
- POSIX-compliant operating system (Linux, macOS) or Windows with appropriate compatibility layers

## Building the Project

```bash
# Clone the repository
git clone https://github.com/Mustafaiqbal2/Distributed-File-System-Conceptual.git
cd Distributed-File-System-Conceptual

# Create build directory
mkdir build && cd build

# Configure and build
cmake ..
make
```

## Usage

### Starting the System

1. Start the name server:
```bash
./dfs_nameserver --port 9000
```

2. Start multiple storage nodes:
```bash
./dfs_storagenode --nameserver localhost:9000 --port 9001 --data-dir /path/to/storage1
./dfs_storagenode --nameserver localhost:9000 --port 9002 --data-dir /path/to/storage2
./dfs_storagenode --nameserver localhost:9000 --port 9003 --data-dir /path/to/storage3
```

3. Use the client to interact with the system:
```bash
./dfs_client --nameserver localhost:9000
```

### Client Commands

```
put <local_file> <remote_path>   # Upload a file to the DFS
get <remote_path> <local_file>   # Download a file from the DFS
mkdir <directory_path>           # Create a directory
ls <directory_path>              # List directory contents
rm <remote_path>                 # Remove a file or directory
stat <remote_path>               # Show file/directory information
help                             # Display available commands
exit                             # Exit the client
```

## Implementation Details

### File Distribution Algorithm

Files are divided into chunks and distributed across storage nodes using a consistent hashing algorithm to ensure even distribution and minimal redistribution when nodes are added or removed.

### Replication Strategy

Each file chunk is replicated across multiple nodes based on a configurable replication factor. The system ensures that replicas are placed on different physical nodes to maximize fault tolerance.

### Consistency Model

The system implements a configurable consistency model that allows for:
- Strong consistency: All reads reflect the most recent writes
- Eventual consistency: The system guarantees that updates will eventually propagate to all nodes
- Read-your-writes consistency: A user always sees their own updates

### Fault Tolerance Mechanisms

When a node failure is detected, the system automatically redistributes data from replicas to maintain the desired replication factor and ensure data availability.

## Testing

The project includes a suite of tests that verify the correctness of the implementation:

```bash
# Run all tests
cd build
ctest

# Run specific test suite
./dfs_tests --gtest_filter=ReplicationTests.*
```

## Future Enhancements

- Implementation of security features (authentication, encryption)
- Support for transactions across multiple files
- Advanced caching mechanisms
- Automated load balancing
- Web interface for system administration

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Author

[Mustafa Iqbal](https://github.com/Mustafaiqbal2)

---

*This project is for educational and conceptual purposes to demonstrate distributed systems principles.*
