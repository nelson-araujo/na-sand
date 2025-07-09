import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';

// Components
import { HeaderComponent } from './header/header';
import { User } from './user/user';

// Data
import { DUMMY_USERS} from './dummy-users';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet,HeaderComponent, User],
  templateUrl: './app.html',
  styleUrl: './app.css'
})
export class App {
  protected title = 'easy-task';
  users = DUMMY_USERS;
}
