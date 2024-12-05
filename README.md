# DDoS scenario with pfifo_fast<br>

# Band-S
Band-S introduces a hidden transmit queue for Ethernet-based automotive networks to protect safety-critical data flows from cram attacks by unauthorized applications. By leveraging a trusted execution environment, Band-S ensures that only authorized applications can utilize this secure pathway, preventing the disruption of critical communications within vehicles. The implementation of Band-S maintains the integrity and security of essential vehicular functions, offering a resilient response to emerging cybersecurity threats in automotive Ethernet networks.

**None**
![image - 2024-03-18T143418 495](https://github.com/AveesLab/sea-me-hackathon-2023/assets/96398568/ecf120d5-66ba-4a16-8fd1-1d07e38f6690)

**Band-S**
![image - 2024-03-18T144521 426](https://github.com/AveesLab/sea-me-hackathon-2023/assets/96398568/909cf771-f3a1-40eb-9133-d07a1774a11f)

## Step 0: Build Kernel Image.

Kernel image with a special DDoS attack prevention method called Band-S in the following link:

- [Kernel image for Band-S](https://github.com/AveesLab/linux-tegra-5.10_s/blob/oe4t-patches-l4t-r35.1/README.md)<br><br>

## Step 1: Make sure you have installed git and cmake
```bash
sudo apt update
sudo apt install git
sudo apt install cmake
```

<br/>

## Step 2: Install OpenJDK Java 8
```bash
sudo apt install openjdk-8-jdk
```

You can check installation

```bash
java -version
```

If you already have openJDK 11 in your system, your default JDK version will be 11.
![스크린샷, 2023-07-07 21-58-18](https://github.com/AveesLab/sea-me-hackathon-2023/assets/96398568/49d28f85-6f4f-4ca6-a971-abfa95dd7f68)

Then you can change the JDK version using the following command:

```bash
sudo update-alternatives --config java
```

Please select java-8 as in the following: 
![스크린샷, 2023-07-07 21-58-41](https://github.com/AveesLab/sea-me-hackathon-2023/assets/96398568/130277ce-b1bd-4c0c-8375-8a877ab1c869)
```bash
java -version
```
![스크린샷, 2023-07-07 21-59-08](https://github.com/AveesLab/sea-me-hackathon-2023/assets/96398568/f3c6b169-3de6-4bba-83ba-087a9e92da07)


<br/>

## Step 3: Install the Boost.Asio library
Boost.Asio is a C++ network library.
```bash
sudo apt install libboost-all-dev
```

<br/>

## Step 4: Build the CommonAPI core runtime

Create a build directory, which is `build-commonapi` in my case.

```bash
cd ~
mkdir build-commonapi && cd build-commonapi
```

Download, build, and install the CommonAPI runtime.

```bash
git clone https://github.com/GENIVI/capicxx-core-runtime.git
cd capicxx-core-runtime/
git checkout 3.2.0
mkdir build
cd build
cmake ..
make -j12
sudo make install
```

Result:

```bash
[100%] Linking C shared library libCommonAPI.so
[100%] Built target CommonAPI
```

<br/>

## Step 5: Build the vsomeip library

Install dependent packages.
```bash
sudo apt install asciidoc source-highlight doxygen graphviz libgtest-dev
```
Download and build the vsomeip library.

```bash
cd ~
cd build-commonapi
git clone https://github.com/COVESA/vsomeip.git
cd vsomeip
git checkout 3.1.20.3
mkdir build
cd build
cmake -DENABLE_SIGNAL_HANDLING=1 -DDIAGNOSIS_ADDRESS=0x10 ..
make -j12
sudo make install
```


Result:

```bash
[100%] Linking CXX executable vsomeipd
[100%] Built target vsomeipd
```

<br/>

## Step 6: Build the CommonAPI SOME/IP runtime library

Download and build the CommonAPI SOME/IP runtime library.

```bash
cd ~
cd build-commonapi
git clone https://github.com/GENIVI/capicxx-someip-runtime.git
cd capicxx-someip-runtime/
git checkout 3.2.0
mkdir build
cd build
cmake -DUSE_INSTALLED_COMMONAPI=OFF ..
make -j12
sudo make install

```

Result:

```bash
[100%] Linking CXX shared library libCommonAPI-SomeIP.so
[100%] Built target CommonAPI-SomeIP
```

#### Add library path
```bash
cd ~
sudo vi .bashrc
```
Add the following line at the end of the .bash file:
```bash
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
```

Source the .bashrc.

```bash
source .bashrc
```
<br/>



## Step 7: Install Open-TEE

Install Open-TEE.
```bash
$ cd $HOME
$ git clone https://github.com/OP-TEE/build.git
$ cd build
$ make -f toolchain.mk -j2
```

Export PATH.
```bash
#If you have downloaded the toolchains as described above, you should have them at $HOME/toolchains/{aarch32/aarch64}, so now we just need to export the paths and then you are ready to starting compiling OP-TEE components.
$ export PATH=$PATH:$HOME/toolchains/aarch32/bin:$HOME/toolchains/aarch64/bin
```

Install optee-client 4.0.0 library.
```bash
$ git clone https://github.com/OP-TEE/optee_client
$ cd optee_client
```

Building using CMake.
```bash
$ mkdir build
$ cd build
$ cmake -DCMAKE_C_COMPILER=arm-linux-gnueabihf-gcc ..
$ make
```


<br/>

## Step 8: Execute Cluster and Image Detecetion with DDoS Scenario

```bash
./do_cluster.sh
./do_detect.sh
./ddos_attacker.py
```
