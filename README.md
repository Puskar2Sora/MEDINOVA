<div align="center">

<!-- LOGO -->
<img src="logo.png" width="30%" alt="MEDINOVA Logo"/>

<h1 style="font-size:50px; margin:0;">MEDINOVA</h1>
<h3>An IoT-Powered Smart Pill Dispenser for Healthcare Automation</h3>

<p><em><strong>Timely doses, healthier lives</strong> — where technology cares.</em></p>

<!-- BADGES -->
<p>
  <img src="https://img.shields.io/badge/ESP8266-NodeMCU-orange?style=flat-square&logo=arduino"/>
  <img src="https://img.shields.io/badge/Language-C++-blue?style=flat-square"/>
  <img src="https://img.shields.io/badge/Category-IoT%20Healthcare%20Tech%20Device%20Prototype-success?style=flat-square"/>
<img src="https://img.shields.io/badge/License-MIT-blue?style=flat-square"/>
</p>

</div>

---

<!-- 🌟 PROJECT PREVIEW -->
<div align="center">
  <img src="hardware/Raw_Circuit.png" width="30%" alt="Medinova Demo"/>
  <p><em>Medinova in motion — smart dispensing with clarity.</em></p>
</div>

---

## 📌 What is MEDINOVA?

<p>
<strong>MEDINOVA</strong> is an innovative IoT-based smart medication dispenser designed to automate and improve medication adherence for patients, especially the elderly or chronically ill. It minimizes human error, prevents missed doses, and empowers independent living with smart scheduling and reminders.
</p>

---

## 🧠 Why Medinova Matters

<ul style="line-height:1.7;">
  <li>Patients often miss or forget medication timing.</li>
  <li>Manual reminders and pill boxes are error-prone.</li>
  <li>Caregivers carry heavy responsibility.</li>
  <li>Healthcare calls for smart automation that’s simple and reliable.</li>
</ul>

<strong>Medinova solves these with automation, alerts, and precision.</strong>

---

## ⚙️ How It Works

<div align="center">
  <img src="hardware/Circuit_Diagram.png" width="30%" alt="Medinova System Architecture"/>
</div>
<br></br>
<table width="100%" cellpadding="10">
  <tr>
    <td><strong>⏱️ Time Tracking</strong></td>
    <td><strong>Servo Dispensing</strong></td>
    <td><strong>Display Alerts</strong></td>
  </tr>
  <tr>
    <td>Your schedule is set either manually or via UI.</td>
    <td>Servo rotates to the correct compartment.</td>
    <td>LCD + buzzer notify the user.</td>
  </tr>
</table>

---

## 📦 Hardware Stack

<table>
<tr><th>Component</th><th>Purpose</th></tr>
<tr><td>ESP8266 / NodeMCU</td><td>Main controller with IoT capability</td></tr>
<tr><td>RTC Module (DS3231)</td><td>Real-time clock for accurate scheduling</td></tr>
<tr><td>Servo Motor</td><td>Dispensing mechanism</td></tr>
<tr><td>I2C LCD Display</td><td>User feedback & alerts</td></tr>
<tr><td>Buzzer</td><td>Attention alert</td></tr>
<tr><td>Breadboard & Wires</td><td>Prototyping base</td></tr>
</table>

---

## 🧠 Software Stack

- 🔧 **Arduino IDE**
- 💻 **C++ (Firmware)**
- 🌐 **IoT-ready architecture**
- 🔄 Easily extensible for apps

---

## ✨ Key Features

<ul style="line-height:1.7;">
  <li>🗓️ Automated pill scheduling</li>
  <li>📤 IoT-connected for future remote insights</li>
  <li>🔊 Alert system with buzzer + LCD</li>
  <li>✔️ Prevents missed doses & overdosing</li>
  <li>🤝 Caregiver reduction, patient autonomy</li>
</ul>

---

<h2>📈 Advantages</h2>

<table>
  <tr>
    <!-- LEFT SIDE: TEXT -->
    <td width="55%" valign="top">

<ul>
  <li>✅ Smart and reliable medication dispensing</li>
  <li>✅ Reduces human dependency and errors</li>
  <li>✅ Prevents missed doses & overdosing</li>
  <li>✅ Encourages patient independence</li>
  <li>✅ Minimizes caregiver workload, allowing remote supervision instead of constant reminders</li>
  <li>✅ Reduces medication errors caused by forgetfulness or confusion</li>
  <li>✅ Cost-effective solution compared to long-term hospitalization or full-time care</li>
  <li>✅ User-friendly design suitable for elderly users with minimal technical knowledge</li>
</ul>
  </td>
  <td width="45%" align="center">
      <img 
        src="hardware/Pin_Diagram.png" 
        alt="Medinova System Diagram" 
        width="100%"
      />
    </td>
  </tr>
</table>

## ⚠️ Current Limitations

<ul style="line-height:1.7;">
  <li>Requires manual refill of pills</li>
  <li>Packaging and hygiene need careful management</li>
  <li>Firmware currently prototype-level</li>
</ul>

---

## 🎯 Use Cases

<ul style="line-height:1.7;">
  <li>🏥 Hospital medication management</li>
  <li>🏡 At-home medication automation</li>
  <li>👵 Senior care homes</li>
  <li>🩺 Chronic disease therapy adherence</li>
</ul>

---

## 🔮 Future Enhancements

<ul style="line-height:1.7;">
  <li>📱 Full mobile app integration</li>
  <li>🔔 Remote notifications for caregivers</li>
  <li>🎙️ Voice assistant + emergency alerts</li>
  <li>🆔 Biometric authentication</li>
  <li>🚨 AI prediction & reminders</li>
</ul>

---

## 👥 Team Behind Medinova

<div align="center">
  <table>
    <tr><th>Name</th><th>Role</th></tr>
    <tr><td>Sankalan Pal</td><td>Leader & Presenter</td></tr>
    <tr><td><strong>Puskar Nath</strong></td><td>Researcher & Presenter</td></tr>
    <tr><td>Shayak Sarkar</td><td>Researcher</td></tr>
    <tr><td>Aniraj Saha</td><td>Visualization</td></tr>
    <tr><td>Samadrita Datta</td><td>Designer</td></tr>
    <tr><td>Pameli Saha</td><td>Designer</td></tr>
  </table>

  <p>Dept of CSE | 2nd Year, 3rd Semester</p>
</div>

---

## 📂 Repo Structure

```text
MEDINOVA/
├── firmware/
├── hardware/
├── docs/
├── demo/
├── images/
└── README.md
```
## 📄 License
<p>This project is licensed under the <strong>MIT License</strong>. See <code>LICENSE</code> for details.</p>
⭐ Support the Project
<p> If you find Medinova useful, show some love: </p> <ul> <li>⭐ Star this repository</li> <li>🍴 Fork it</li> <li>💬 Suggest features or improvements</li> </ul> <div align="center"> <h2>MEDINOVA — Engineering care, one dose at a time 💙</h2> </div>
