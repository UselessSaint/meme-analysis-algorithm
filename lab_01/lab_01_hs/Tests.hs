module Main where

import Data.List
import Data.Matrix
import System.IO

import Lev_matrix
import Dam_lev_matrix
import Dam_lev_rec

first_arg_empty :: IO()
first_arg_empty = do
    let s1 = ""
    let s2 = "ABC"
    
    if (getElem 1 4 (lev_mtr_abs s1 s2)) == 3
        then putStr "first_arg_empty Lev_mtr : true\n"
        else putStr "first_arg_empty Lev_mtr : false\n"
        
    if (getElem 1 4 (dam_lev_mtr_abs s1 s2)) == 3
        then putStr "first_arg_empty Dam_lev_mtr: true\n"
        else putStr "first_arg_empty Dam_lev_mtr: false\n"
        
    if (dam_lev_rec s1 s2) == 3
        then putStr "first_arg_empty Dam_lev_rec: true\n"
        else putStr "first_arg_empty Dam_lev_rec: false\n"

second_arg_empty :: IO()
second_arg_empty = do
    let s1 = "ABC"
    let s2 = ""
    
    if (getElem 4 1 (lev_mtr_abs s1 s2)) == 3
        then putStr "second_arg_empty Lev_mtr : true\n"
        else putStr "second_arg_empty Lev_mtr : false\n"
        
    if (getElem 4 1 (dam_lev_mtr_abs s1 s2)) == 3
        then putStr "second_arg_empty Dam_lev_mtr: true\n"
        else putStr "second_arg_empty Dam_lev_mtr: false\n"
        
    if (dam_lev_rec s1 s2) == 3
        then putStr "second_arg_empty Dam_lev_rec: true\n"
        else putStr "second_arg_empty Dam_lev_rec: false\n"

normal_test :: IO()
normal_test = do
    let s1 = "ABC"
    let s2 = "DTF"
 
    if (getElem 4 4 (lev_mtr_abs s1 s2)) == 3
        then putStr "normal_test Lev_mtr : true\n"
        else putStr "normal_test Lev_mtr : false\n"
        
    if (getElem 4 4 (dam_lev_mtr_abs s1 s2)) == 3
        then putStr "normal_test Dam_lev_mtr: true\n"
        else putStr "normal_test Dam_lev_mtr: false\n"
        
    if (dam_lev_rec s1 s2) == 3
        then putStr "normal_test Dam_lev_rec: true\n"
        else putStr "normal_test Dam_lev_rec: false\n"
        
both_args_empty :: IO()
both_args_empty = do
    let s1 = ""
    let s2 = ""
    
    if (getElem 1 1 (lev_mtr_abs s1 s2)) == 0
        then putStr "both_args_empty Lev_mtr : true\n"
        else putStr "both_args_empty Lev_mtr : false\n"
        
    if (getElem 1 1 (dam_lev_mtr_abs s1 s2)) == 0
        then putStr "both_args_empty Dam_lev_mtr: true\n"
        else putStr "both_args_empty Dam_lev_mtr: false\n"
        
    if (dam_lev_rec s1 s2) == 0
        then putStr "both_args_empty Dam_lev_rec: true\n"
        else putStr "both_args_empty Dam_lev_rec: false\n"

main :: IO()
main = do
    first_arg_empty
    putStr "\n"
    second_arg_empty
    putStr "\n"
    normal_test
    putStr "\n"
    both_args_empty
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    