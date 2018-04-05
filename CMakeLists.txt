cmake_minimum_required(VERSION 3.10)
project(C_TUT)

set(CMAKE_CXX_STANDARD 11)

add_executable(C_TUT main.cpp Block.cpp Block.h Blockchain.cpp Blockchain.h sha256.cpp sha256.h Wallet.cpp Wallet.h Transaction.cpp Transaction.h Ecdsa.cpp Ecdsa.hpp CurvePoint.cpp CurvePoint.hpp Sha256Hash.cpp Sha256Hash.hpp Uint256.cpp Uint256.hpp Utils.cpp Utils.hpp FieldInt.cpp FieldInt.hpp)