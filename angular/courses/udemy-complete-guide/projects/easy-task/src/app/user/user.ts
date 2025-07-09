import { Component, computed, signal, Input, input } from '@angular/core';

import { DUMMY_USERS } from '../dummy-users';

const randomIndex = Math.floor(Math.random() * DUMMY_USERS.length);

@Component({
  selector: 'app-user',
  imports: [],
  templateUrl: './user.html',
  styleUrl: './user.css'
})
export class User {
  /****************************************************************************
   Using zone.js - random user test
   ***************************************************************************/
  // selectedUser = DUMMY_USERS[randomIndex];
  //
  // onSelectUser(){
  //   // console.log("clicked");
  //
  //   const randomIndex = Math.floor(Math.random() * DUMMY_USERS.length);
  //   this.selectedUser = DUMMY_USERS[randomIndex];
  // }
  //
  // get user image location
  // get imagePath(){
  //   return 'assets/users/' + this.selectedUser.avatar
  // }

  /****************************************************************************
   Using signals - random user test
   ****************************************************************************/
  // selectedUser = signal(DUMMY_USERS[randomIndex]);
  // imagePath = computed(() => 'assets/users/' + this.selectedUser().avatar);
  //
  // onSelectUser(){
  //   // Randomize a user
  //   const randomIndex = Math.floor(Math.random() * DUMMY_USERS.length);
  //   console.log(DUMMY_USERS[randomIndex]);
  //   this.selectedUser.set(DUMMY_USERS[randomIndex]);
  // }

  /****************************************************************************
   Using signals - random user test
   ****************************************************************************/

  /****************************************************************************
   Input using a decorator with Input
   ****************************************************************************/
  // User properties to access from HTML
  // @Input({required:true}) avatar!: string;
  // @Input({required:true}) name!: string;
  //
  // get imagePath(){
  //   return 'assets/users/' + this.avatar
  // }
  //
  // onSelectUser(){

  // }

  /****************************************************************************
   Input using a signal with input
   ****************************************************************************/
  avatar = input.required<string>();
  name= input.required<string>();

  // Using a computed function means it's only recalculated when avatar changes
  // therefore more efficient than using a fuction where it would calculate it
  // every time the page is updated
  imagePath = computed(()=> {
    return 'assets/users/' + this.avatar();
  })

  onSelectUser(){
    // Empty
  }

}
