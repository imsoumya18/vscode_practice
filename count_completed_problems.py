#!/usr/bin/env python3
"""
Script to count completed problems per week from README.md
Separates new and revision problems with total and solved counts
"""

import re
import subprocess
from datetime import date


def count_problems_by_section(section_content):
    """
    Count total, solved, and difficulty breakdown in a section.

    Returns:
        tuple: (total_count, solved_count, easy, medium, hard)
    """
    total_problems = len(re.findall(r'\|\s*`\d+\.\d+\.\d+`\s*\|', section_content))
    solved_problems = len(re.findall(r'\|\s*✅\s*\|', section_content))
    easy   = len(re.findall(r'\|\s*🟢\s*\|', section_content))
    medium = len(re.findall(r'\|\s*🟡\s*\|', section_content))
    hard   = len(re.findall(r'\|\s*🔴\s*\|', section_content))
    return total_problems, solved_problems, easy, medium, hard



def count_completed_problems(file_path):
    """
    Count the number of completed problems in each week from the README.md file.
    Separates new and revision problems.
    
    Args:
        file_path (str): Path to the README.md file
    
    Returns:
        dict: Dictionary with week numbers as keys and problem counts as values
    """
    with open(file_path, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Dictionary to store counts for each week
    week_data = {}
    
    # Find all week sections
    for week_num in range(1, 17):  # Weeks 1-16
        # Match the specific week section
        if week_num < 16:
            pattern = rf'## 📆 Week {week_num}\n(.*?)## 📆 Week {week_num + 1}'
        else:
            pattern = rf'## 📆 Week {week_num}\n(.*?)## 💡 Tips'
        
        week_match = re.search(pattern, content, re.DOTALL)
        
        if not week_match:
            # Try alternative end pattern for last week
            pattern = rf'## 📆 Week {week_num}\n(.*?)(?:---\n\n## |$)'
            week_match = re.search(pattern, content, re.DOTALL)
        
        if week_match:
            week_content = week_match.group(1)
            
            # Find New Problems section
            new_match = re.search(r'### 🆕 New Problems(.*?)### 🔄 Revision', 
                                 week_content, re.DOTALL)
            # Find Revision section - ends with newline followed by ---
            revision_match = re.search(r'### 🔄 Revision(.*?)(?:\n---|\Z)', 
                                      week_content, re.DOTALL)
            
            new_total, new_solved, new_easy, new_medium, new_hard = 0, 0, 0, 0, 0
            revision_total, revision_solved, rev_easy, rev_medium, rev_hard = 0, 0, 0, 0, 0

            if new_match:
                new_total, new_solved, new_easy, new_medium, new_hard = count_problems_by_section(new_match.group(1))

            if revision_match:
                revision_total, revision_solved, rev_easy, rev_medium, rev_hard = count_problems_by_section(revision_match.group(1))

            week_data[week_num] = {
                'new': {'total': new_total, 'solved': new_solved},
                'revision': {'total': revision_total, 'solved': revision_solved},
                'easy': new_easy + rev_easy,
                'medium': new_medium + rev_medium,
                'hard': new_hard + rev_hard,
            }
    
    return week_data



def display_results(week_data):
    """
    Display the results in the requested format.
    
    Args:
        week_data (dict): Dictionary with week numbers and problem counts
    """
    print("\n" + "=" * 60)
    print("📊 COMPLETED PROBLEMS PER WEEK")
    print("=" * 60)
    
    total_new_problems = 0
    total_new_solved = 0
    total_revision_problems = 0
    total_revision_solved = 0
    
    for week_num in sorted(week_data.keys()):
        data = week_data[week_num]
        new_total = data['new']['total']
        new_solved = data['new']['solved']
        rev_total = data['revision']['total']
        rev_solved = data['revision']['solved']
        
        # Accumulate totals
        total_new_problems += new_total
        total_new_solved += new_solved
        total_revision_problems += rev_total
        total_revision_solved += rev_solved
        
        print(f"\nWeek {week_num}:")
        
        # Determine status emoji for New section
        if new_total > 0 and new_solved == new_total:
            new_status = "☑️  "
        elif new_solved > 0:
            new_status = "🔄 "
        else:
            new_status = "   "
        
        # Determine status emoji for Revision section
        if rev_total > 0 and rev_solved == rev_total:
            rev_status = "☑️  "
        elif rev_solved > 0:
            rev_status = "🔄 "
        else:
            rev_status = "   "
        
        print(f"  {new_status}New:      total: {new_total:3d}, solved: {new_solved:3d}")
        print(f"  {rev_status}Revision: total: {rev_total:3d}, solved: {rev_solved:3d}")
    
    print("\n" + "=" * 60)
    print("OVERALL SUMMARY:")
    print(f"  New:      total: {total_new_problems:3d}, solved: {total_new_solved:3d}")
    print(f"  Revision: total: {total_revision_problems:3d}, solved: {total_revision_solved:3d}")
    print(f"  TOTAL:    total: {total_new_problems + total_revision_problems:3d}, solved: {total_new_solved + total_revision_solved:3d}")
    print("=" * 60)
    print()


def _cell(solved, total):
    """Format a solved/total cell with status emoji."""
    if total == 0:
        return "—"
    if solved == total:
        return f"✅ &nbsp; **{solved} / {total}**"
    if solved > 0:
        return f"🔄 &nbsp; {solved} / {total}"
    return f"0 / {total}"


def _week_label(week_num, ns, nt, rs, rt):
    """Format the week label with a status indicator."""
    if ns == nt and rs == rt and nt > 0 and rt > 0:
        return f"✅ **{week_num}**"
    if ns > 0 or rs > 0:
        return f"🔄 **{week_num}**"
    return f"**{week_num}**"


def generate_progress_table(week_data):
    """Generate a markdown progress table string."""
    lines = [
        "<!-- PROGRESS_START -->",
        "## 📈 Current Progress",
        "",
        "| &nbsp; Week &nbsp; | &nbsp;&nbsp;&nbsp; 🆕 New Problems &nbsp;&nbsp;&nbsp; | &nbsp;&nbsp;&nbsp; 🔄 Revision Problems &nbsp;&nbsp;&nbsp; | &nbsp;&nbsp;&nbsp; 📊 Total Problems &nbsp;&nbsp;&nbsp; |",
        "|:------:|:---------------------:|:------------------------:|:---------------------:|",
    ]

    total_new_solved = total_new_total = 0
    total_rev_solved = total_rev_total = 0

    for week_num in sorted(week_data.keys()):
        data = week_data[week_num]
        ns, nt = data['new']['solved'], data['new']['total']
        rs, rt = data['revision']['solved'], data['revision']['total']

        total_new_solved += ns
        total_new_total += nt
        total_rev_solved += rs
        total_rev_total += rt

        week_col = _week_label(week_num, ns, nt, rs, rt)
        lines.append(f"| {week_col} | {_cell(ns, nt)} | {_cell(rs, rt)} | {_cell(ns + rs, nt + rt)} |")

    grand_solved = total_new_solved + total_rev_solved
    grand_total = total_new_total + total_rev_total
    lines.append(
        f"| **Total** | {_cell(total_new_solved, total_new_total)} "
        f"| {_cell(total_rev_solved, total_rev_total)} "
        f"| {_cell(grand_solved, grand_total)} |"
    )
    lines += ["", f"*Last updated: {date.today().strftime('%Y-%m-%d')}*", "", "<!-- PROGRESS_END -->"]
    return "\n".join(lines)


def update_readme_progress(week_data, readme_path):
    """Insert or replace the progress table in README.md."""
    with open(readme_path, 'r', encoding='utf-8') as f:
        content = f.read()

    table = generate_progress_table(week_data)

    if '<!-- PROGRESS_START -->' in content and '<!-- PROGRESS_END -->' in content:
        new_content = re.sub(
            r'<!-- PROGRESS_START -->.*?<!-- PROGRESS_END -->',
            table,
            content,
            flags=re.DOTALL,
        )
    else:
        # Insert after the subtitle line on first run
        subtitle = '**📚 Total:** 455 problems | **⏱️ Duration:** 16 weeks | **🎓 Goal:** Master DSA\n'
        if subtitle in content:
            new_content = content.replace(subtitle, subtitle + '\n' + table + '\n')
        else:
            new_content = content + '\n' + table + '\n'

    with open(readme_path, 'w', encoding='utf-8') as f:
        f.write(new_content)

    print("✅ README.md progress table updated!")


def count_problems_from_string(content):
    """Run count_completed_problems logic on an in-memory string."""
    week_data = {}
    for week_num in range(1, 17):
        if week_num < 16:
            pattern = rf'## 📆 Week {week_num}\n(.*?)## 📆 Week {week_num + 1}'
        else:
            pattern = rf'## 📆 Week {week_num}\n(.*?)## 💡 Tips'

        week_match = re.search(pattern, content, re.DOTALL)
        if not week_match:
            pattern = rf'## 📆 Week {week_num}\n(.*?)(?:---\n\n## |$)'
            week_match = re.search(pattern, content, re.DOTALL)

        if week_match:
            week_content = week_match.group(1)
            new_match = re.search(r'### 🆕 New Problems(.*?)### 🔄 Revision',
                                  week_content, re.DOTALL)
            revision_match = re.search(r'### 🔄 Revision(.*?)(?:\n---|\Z)',
                                       week_content, re.DOTALL)

            nt, ns, *_ = count_problems_by_section(new_match.group(1)) if new_match else (0, 0, 0, 0, 0)
            rt, rs, *_ = count_problems_by_section(revision_match.group(1)) if revision_match else (0, 0, 0, 0, 0)

            week_data[week_num] = {
                'new':      {'total': nt, 'solved': ns},
                'revision': {'total': rt, 'solved': rs},
            }
    return week_data


def _sum_solved(week_data):
    new_s = sum(d['new']['solved']      for d in week_data.values())
    rev_s = sum(d['revision']['solved'] for d in week_data.values())
    return new_s, rev_s


def main():
    """Main function to run the script."""
    file_path = '/Users/soumya/VS Code Projects/vscode_practice/README.md'

    try:
        week_data = count_completed_problems(file_path)
        update_readme_progress(week_data, file_path)

        # Delta since last commit
        try:
            prev_content = subprocess.check_output(
                ['git', 'show', 'HEAD:README.md'],
                cwd='/Users/soumya/VS Code Projects/vscode_practice',
                stderr=subprocess.DEVNULL,
            ).decode('utf-8')
            prev_data = count_problems_from_string(prev_content)
            prev_new_s, prev_rev_s = _sum_solved(prev_data)
        except subprocess.CalledProcessError:
            # No previous commit (initial commit)
            prev_new_s, prev_rev_s = 0, 0

        cur_new_s, cur_rev_s = _sum_solved(week_data)
        delta_new = cur_new_s - prev_new_s
        delta_rev = cur_rev_s - prev_rev_s
        delta_total = delta_new + delta_rev

        print(f"   🆕 New solved this session:      {delta_new:+d}")
        print(f"   🔄 Revisions solved this session: {delta_rev:+d}")
        print(f"   📊 Total solved this session:     {delta_total:+d}")

    except FileNotFoundError:
        print(f"❌ File not found: {file_path}")
    except Exception as e:
        print(f"❌ Error: {e}")


if __name__ == "__main__":
    main()
