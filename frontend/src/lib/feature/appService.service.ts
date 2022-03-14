import { HttpClient } from "@angular/common/http";
import { Injectable } from "@angular/core";
import { Observable } from "rxjs";
import { List } from "../data-access/list";
import { Reminder } from "../data-access/reminder";
import { ReminderApp } from "../data-access/reminderApp";

@Injectable({providedIn:'root'})

export class AppService{
   constructor(private httpClient: HttpClient){}

  getApp(): Observable<ReminderApp> {
    return this.httpClient.get<ReminderApp>('http://localhost:8080/api/app');
  }
  postList(list: List): Observable<List>{
    console.log(list);
    return this.httpClient.post<List>('http://localhost:8080/api/app/lists',list);
  }
  postReminder(listId: number, reminder: Reminder): Observable<Reminder>{
    return this.httpClient.post<Reminder>('http://localhost:8080/api/app/lists/'+listId+'/reminders', reminder);
  }
  putList(list: List): Observable<List>{
    return this.httpClient.put<List>('http://localhost:8080/api/app/lists/'+list.id, list);
  }
  putReminder(listId: number, reminder: Reminder): Observable<Reminder>{
    return this.httpClient.put<Reminder>('http://localhost:8080/api/app/lists/'+listId+'/reminders/'+reminder.id, reminder);
  }
  deleteList(listId: number): Observable<List>{
    return this.httpClient.delete<List>('http://localhost:8080/api/app/lists/'+listId);
  }
  deleteReminder(listId: number, reminderId: number): Observable<Reminder>{
    return this.httpClient.delete<Reminder>('http://localhost:8080/api/app/lists/'+listId+'/reminders/'+reminderId);
  }
  getToday() : string{
    let todayDate: Date = new Date();
    return todayDate.toISOString().substring(0, 10);
  }
}
