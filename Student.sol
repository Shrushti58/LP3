// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Student{

    struct Stud{
        uint256 roll_no;
        string name;
    }

    Stud[] public studarr;

    function addStud(uint r,string memory n) public{
        for(uint256 i=0;i<studarr.length;i++){
            if(r==studarr[i].roll_no){
                revert("Roll no already Exists");
            }
          
        }
          studarr.push(Stud(r,n));
    }

    function showallstud() public view returns(Stud[] memory){
        return studarr;
    }

    function deletestud(uint256 r) public returns(uint256){
        for(uint256 i=0;i<studarr.length;i++){
            if(r==studarr[i].roll_no){
                delete studarr[i];
                return i;
            }
        }
        revert("Roll no not found!");

    }

    
}
