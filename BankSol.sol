// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank{

    uint256 balance;
    address public accowner;

    constructor(){
        accowner=msg.sender;
    }

    function Deposit() public payable {
        require(accowner==msg.sender,"You are not owner of Account!");
        require(msg.value>0,"Amount cannot be less than zero!");
        balance+=msg.value;
    }

    function Withdraw() public payable {
          require(accowner==msg.sender,"You are not owner of Account!");
        require(msg.value<=balance,"Insufficeint Balance!");
        balance-=msg.value;
    }

    function showBalance() public view returns(uint256){
          require(accowner==msg.sender,"You are not owner of Account!");
          return balance;
    }

}
